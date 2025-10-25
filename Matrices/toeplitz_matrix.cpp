/*
Toeplitz matrix: A matrix is said to be toeplitz matrix if each diagonal have same elements.
M[i,j] = M[i-1,j-1];
*/

#include<memory>
#include<iostream>

class ToeplitzMatrix{
    private:
        std::unique_ptr<int[]> matrix;
        int n;
    public:
        ToeplitzMatrix(int dimensions);
        void set(int i,int j, int value);
        int get(int i,int j);
        void display();
};

ToeplitzMatrix::ToeplitzMatrix(int dimensions):n(dimensions){
    matrix = std::make_unique<int[]>(2*n-1);
}

void ToeplitzMatrix::set(int i,int j,int value){
    if(i==0){
        matrix[j] = value;
    }else if(j==0){
        matrix[n+i-1] = value;
    }
}

int ToeplitzMatrix::get(int i,int j){
    if(i<=j){
        return matrix[j-i];
    }
    else{
        return matrix[n+i-j-1];
    }
}

void ToeplitzMatrix::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<=j){
                std::cout<<matrix[j-i]<<" ";
            }
            else{
                std::cout<<matrix[n+i-j-1]<<" ";
            }
        }
        std::cout<<"\n";
    }
}

int main(){
    std::cout<<"--------------------\n";
    std::cout<<"Toeplitz matrix\n";
    int dimensions;
    // std::cout<<"Enter dimensions: ";
    // std::cin>>dimensions;
    dimensions=5;
    ToeplitzMatrix tm(dimensions);
    for(int i=0,random_val=1;i<dimensions;i++){
        for(int j=0;j<dimensions;j++){
            if(i==0){
                tm.set(i,j,random_val++);
            }else if(j==0){
                tm.set(i,j,random_val++);
            }
        }
    }
    tm.display();
    std::cout<<"--------------------\n";
    return 0;
}
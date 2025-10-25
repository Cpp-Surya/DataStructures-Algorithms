/*
Tri-diagonal-matrix: A matrix which contains non-zero elements only in main diagonal, lower diagonal and upper diagonal.
*/

#include<memory>
#include<iostream>

class TriDiagonalMatrix{
    private:
        std::unique_ptr<int[]> matrix;
        int n;
    public:
        TriDiagonalMatrix(int dimensions);
        void set(int i,int j,int value);
        int get(int i,int j);
        void display();
};

TriDiagonalMatrix::TriDiagonalMatrix(int dimensions):n(dimensions){
    matrix = std::make_unique<int[]>((3*n)-2);
}

void TriDiagonalMatrix::set(int i,int j,int value){
    if(i-j == 1){
        matrix[i-1] = value;
    }else if(i-j == 0){
        matrix[n-1+i] = value;
    }else if(i-j == -1){
        matrix[(2*n)-1+i] = value;
    }
}

int TriDiagonalMatrix::get(int i,int j){
    if(i-j == 1){
        return matrix[i-1];
    }else if(i-j == 0){
        return matrix[n-1+i];
    }else if(i-j == -1){
        return matrix[(2*n)-1+i];
    }else{
        return 0; 
    }
}

void TriDiagonalMatrix::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i-j == 1){
                std::cout<<matrix[i-1]<<" ";
            }else if(i-j == 0){
                std::cout<<matrix[n-1+i]<<" ";
            }else if(i-j == -1){
                std::cout<<matrix[(2*n)-1+i]<<" ";
            }else{
                std::cout<<0<<" "; 
            }
        }
        std::cout<<"\n";
    }
}

int main(){
    std::cout<<"--------------------\n";
    std::cout<<"Tri-diagonal matrix\n";
    int dimensions;
    // std::cout<<"Enter dimensions: ";
    // std::cin>>dimensions;
    dimensions=4;
    TriDiagonalMatrix tm(dimensions);
    for(int i=0,random_val=1;i<dimensions;i++){
        for(int j=0;j<dimensions;j++){
            if(i-j == 1 || i-j == 0 || i-j == -1){
                tm.set(i,j,random_val++);
            }
        }
    }
    tm.display();
    std::cout<<"--------------------\n";

    return 0;
}
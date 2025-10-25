/*
Symmetric matrix: if M[i,j] = M[j,i] then it is a symmetric matrix.
*/

#include<memory>
#include<iostream>

class SymmetricMatrix{
    private:
        std::unique_ptr<int[]> matrix;
        int n;
    public:
        SymmetricMatrix(int dimensions);
        void set(int i,int j,int value);
        int get(int i,int j);
        void display();
};

SymmetricMatrix::SymmetricMatrix(int dimensions):n(dimensions){
    matrix = std::make_unique<int[]>((n*(n+1))/2);
}

void SymmetricMatrix::set(int i,int j,int value){
    if(i>=j){
        //Row major mapping
        matrix[(i*(i+1)/2)+j] = value;
    }
}

int SymmetricMatrix::get(int i, int j){
    if(i>=j){
        //Row major mapping
        return matrix[(i*(i+1)/2)+j];
    }else{
        return matrix[(j*(j+1)/2)+i];
    }
}

void SymmetricMatrix::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i>=j){
                std::cout<<matrix[(i*(i+1)/2)+j]<<" ";
            }else{
                std::cout<<matrix[(j*(j+1)/2)+i]<<" ";
            }
        }
        std::cout<<"\n";
    }
}

int main(){
    std::cout<<"--------------------\n";
    std::cout<<"Symmetric matrix\n";
    int dimensions;
    //std::cout<<"Enter dimensions: ";
    //std::cin>>dimensions;
    dimensions = 4;
    SymmetricMatrix sm(dimensions);
    for(int i=0;i<dimensions;i++){
        int random_val{1};
        for(int j=0;j<dimensions;j++,random_val++){
            if(i>=j){
                sm.set(i,j,random_val);
            }
        }
    }
    sm.display();
    std::cout<<"--------------------\n";
    return 0;
}
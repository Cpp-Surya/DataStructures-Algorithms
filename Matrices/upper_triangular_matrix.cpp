/*
Upper Triangular Matrix: A square matrix with non-zero elements in the upper triangular part and zeros in the lower triangular part.
*/

#include <iostream>
#include <memory>

class UpperTriangularMatrix{
    private:
        std::unique_ptr<int[]> matrix;
        int n;
    public:
        UpperTriangularMatrix(int dimensions);
        void set(int i,int j,int value);
        int get(int i,int j);
        void display();
};

UpperTriangularMatrix::UpperTriangularMatrix(int dimensions):n(dimensions){
    matrix = std::make_unique<int[]>(n*(n+1)/2);
}

void UpperTriangularMatrix::set(int i,int j,int value){
    if(i<=j){
        //Row major mapping
        //matrix[n*i-((i-1)*i/2)+(j-i)] = value;
        //Column major mapping
        matrix[(j*(j+1)/2)+i] = value;
    }
}

int UpperTriangularMatrix::get(int i,int j){
    if(i<=j){
        //Row major mapping
        // return matrix[n*i-((i-1)*i/2)+(j-i)];
        //Column major mapping
        return matrix[(j*(j+1)/2)+i];
    }else{
        return 0;
    }
}

void UpperTriangularMatrix::display(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<=j){
                //Row major mapping
                //std::cout<<matrix[n*i-((i-1)*i/2)+(j-i)]<<" ";
                //Column major mapping
                std::cout<<matrix[(j*(j+1)/2)+i]<<" ";
            }else{
                std::cout<<0<<" ";
            }
        }
        std::cout<<"\n";
    }
}

int main()
{
    std::cout<<"--------------------\n";
    std::cout<<"Upper triangular matrix\n";
    // std::cout<<"Enter dimensions: ";
    int dimensions;
    // std::cin>>dimensions;
    dimensions = 5;
    UpperTriangularMatrix um(dimensions);
    int random_value{1};
    for(int i=0;i<dimensions;i++){
        for(int j=0;j<dimensions;j++){
            if(i<=j){
                um.set(i,j,random_value++);
            }
        }
    }
    um.display();
    std::cout<<"--------------------\n";
    return 0;
}
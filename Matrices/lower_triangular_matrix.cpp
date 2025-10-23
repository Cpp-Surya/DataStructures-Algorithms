#include <memory>
#include <iostream>

class LowerTriangularMatrix{
    public:
        LowerTriangularMatrix(int dimension);
        void set(int i, int j, int value);
        int get(int i, int j);
        void display();
    
    private:
        std::unique_ptr<int[]> matrix;
        int size;
};

LowerTriangularMatrix::LowerTriangularMatrix(int dimension):size(dimension){
    matrix = std::make_unique<int[]>((size*(size+1))/2);
}

void LowerTriangularMatrix::set(int i, int j, int value){
    if(i>=j){
        //Row major mapping
        //matrix[(i*(i+1)/2)+j] = value;

        //Column major mapping
        matrix[(size*j-((j*(j-1))/2)+(i-j))] = value;
    }
}

int LowerTriangularMatrix::get(int i, int j){
    if(i>=j){
        //Row major mapping
        //return matrix[(i*(i+1)/2)+j];

        //Column major mapping
        return matrix[(size*j-((j*(j-1))/2)+(i-j))];
    }else{
        return 0;
    }
}

void LowerTriangularMatrix::display(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i>=j){
                //Row major mapping
                //std::cout<<matrix[(i*(i+1)/2)+j]<<" ";

                //Column major mapping
                std::cout<<matrix[(size*j-((j*(j-1))/2)+(i-j))]<<" ";
            }else{
                std::cout<<0<<" ";
            }
        }
        std::cout<<"\n";
    }
}


int main(){
    std::cout<<"--------------------\n";
    std::cout<<"Lower triangular matrix\n";
    int dimensions=5,random_num{1};
    LowerTriangularMatrix lm(dimensions);
    for(int i=0;i<dimensions;i++){
        for(int j=0;j<dimensions;j++){
            if(i>=j){
                lm.set(i,j,random_num++);
            }
        }
    }
    lm.display();
    std::cout<<"--------------------\n";
    return 0;
}
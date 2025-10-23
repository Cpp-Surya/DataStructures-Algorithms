#include <memory>
#include <iostream>

class DiagonalMatrix{
    public:
        DiagonalMatrix(int n):size(n){
            A = std::make_unique<int[]>(size);
        }

        void set(int i, int j, int value){
            if(i==j){
                A[i] = value;
            }
        }

        int get(int i, int j){
            if(i==j){
                return A[i];
            }else{
                return 0;
            }
        }

        void display(){
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    if(i==j){
                        std::cout<<A[i]<<" ";
                    }else{
                        std::cout<<0<<" ";
                    }
                }
                std::cout<<"\n";
            }
        }

    private:
        std::unique_ptr<int[]> A;
        size_t size;
};

int main(){
    std::cout<<"--------------------\n";
    std::cout<<"Diagonal matrix\n";
    DiagonalMatrix m(5);
    for(int i=0,j=0,value=55;i<5&&j<5;i++,j++,value+=10){
        m.set(i,j,value);
    }
    m.display();
    std::cout<<"--------------------\n";
}
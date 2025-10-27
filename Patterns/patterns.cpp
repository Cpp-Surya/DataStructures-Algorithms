#include<iostream>

void pattern1(int n){
    /*
        * * * * *
        * * * * *
        * * * * *
        * * * * *
        * * * * *
    */
    for(int row=0;row<n;row++){
        for(int column=0;column<n;column++){
            std::cout<<"* ";
        }
        std::cout<<"\n";
    }
}

void pattern2(int n){
    /*
        * 
        * *
        * * *
        * * * *
        * * * * *
    */
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            std::cout<<"* ";
        }
        std::cout<<"\n";
    }
}

void pattern3(int n){
    /*
        1
        1 2
        1 2 3
        1 2 3 4
        1 2 3 4 5
    */
   for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            std::cout<<j<<" ";
        }
        std::cout<<"\n";
   }
}

void pattern4(int n){
    /*
        1
        2 2
        3 3 3
        4 4 4 4
        5 5 5 5 5
    */
   for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            std::cout<<i<<" ";
        }
        std::cout<<"\n";
   }
}

void pattern5(int n){
    /*
        * * * * *
        * * * *
        * * *
        * *
        * 
    */
   for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            std::cout<<"* ";
        }
        std::cout<<"\n";
   }
}

void pattern6(int n){
    /*
        1 2 3 4 5
        1 2 3 4
        1 2 3
        1 2
        1
    */
   for(int i=0;i<n;i++){
        for(int j=1;j<=n-i;j++){
            std::cout<<j<<" ";
        }
        std::cout<<"\n";
   }
}

void pattern7(int n){
    /*
            *
           ***
          *****
         *******
        *********
    */
   for(int i=0;i<n;i++){
        //for space
        for(int j=0;j<n-i-1;j++){
            std::cout<<" ";
        }
        //for star
        for(int j=0;j<2*i+1;j++){
            std::cout<<"*";
        }
        //for space
        for(int j=0;j<n-i-1;j++){
            std::cout<<" ";
        }
        std::cout<<"\n";
   }
}

void pattern8(int n){
    /*
        *********
         *******
          *****
           ***
            *
    */
   for(int i=0;i<n;i++){
        //for space
        for(int j=0;j<i;j++){
            std::cout<<" ";
        }
        //for star
        for(int j=0;j<2*n-(2*i+1);j++){
            std::cout<<"*";
        }
        //for space
        for(int j=0;j<i;j++){
            std::cout<<" ";
        }
        std::cout<<"\n";
   }
}

void pattern9(int n){
    /*
            *
           ***
          *****
         *******
        *********
        *********
         *******
          *****
           ***
            *
    */
   pattern7(n);
   pattern8(n);
}

void pattern10(int n){
    /*
        *
        **
        ***
        ****
        *****
        ****
        ***
        **
        *
    */
   for(int i=0;i<2*n-1;i++){
        if(i<n){
            for(int j=0;j<=i;j++){
                std::cout<<"*";
            }
            std::cout<<"\n";
        }else{
            for(int j=0;j<2*n-i-1;j++){
                std::cout<<"*";
            }
            std::cout<<"\n";
        }
   }
}

int main(){
    std::cout<<"-----------------\n";
    int n;
    // std::cout<<"Enter input: ";
    // std::cin>>n;
    n=5;
    // pattern1(n);
    // pattern2(n);
    // pattern3(n);
    // pattern4(n);
    // pattern5(n);
    // pattern6(n);
    // pattern7(n);
    // pattern8(n);
    // pattern9(n);
    pattern10(n);
    std::cout<<"-----------------\n";
    return 0;
}
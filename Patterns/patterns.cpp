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

void pattern11(int n){
    /*
        1
        0 1
        1 0 1
        0 1 0 1
        1 0 1 0 1
    */
    for(int i=0;i<n;i++){
        int start;
        if(i%2 == 0){
            start = 1;
        }else{
            start = 0;
        }
        for(int j=0;j<=i;j++){
            std::cout<<start<<" ";
            start=1-start;
        }
        std::cout<<"\n";
    }
}

void pattern12(int n){
    /*
        1      1
        12    21
        123  321
        12344321
        
    */
    for(int i=1;i<=n;i++){
        //for number
        for(int j=1;j<=i;j++){
            std::cout<<j;
        }
        //for space
        for(int j=1;j<=2*(n-i);j++){
            std::cout<<" ";
        }
        //for number
        for(int j=i;j>=1;j--){
            std::cout<<j;
        }
        std::cout<<"\n";
    }
}

void pattern13(int n){
    /*
        1 
        2 3 
        4 5 6 
        7 8 9 10 
        11 12 13 14 15
    */
    int start=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            std::cout<<start++<<" ";
        }
        std::cout<<"\n";
    }
}

void pattern14(int n){
    /*
        A
        AB
        ABC
        ABCD
        ABCDE
    */
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            std::cout<<(char)(65+j);
        }
        std::cout<<"\n";
    }
}

void pattern15(int n){
    /*
        ABCDE
        ABCD
        ABC
        AB
        A
    */
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            std::cout<<(char)(65+j);
        }
        std::cout<<"\n";
    }
}

void pattern16(int n){
    /*
        A
        BB
        CCC
        DDDD
        EEEEE
    */
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            std::cout<<(char)(65+i);
        }
        std::cout<<"\n";
    }
}

void pattern17(int n){
    /*
         A   
        ABA  
       ABCBA 
      ABCDCBA
    */
    for(int i=0;i<n;i++){
        //for space
        for(int j=0;j<n-i-1;j++){
            std::cout<<" ";
        }
        
        //for characters
        for(int j=0;j<=i;j++){
            std::cout<<(char)(65+j);
        }
        
        for(int j=i;j>0;j--){
            std::cout<<(char)(65+j-1);
        }
        
        //for space
        for(int j=0;j<n-i-1;j++){
            std::cout<<" ";
        }
        std::cout<<"\n";
    }
}

void pattern18(int n){
    /*
        E 
        D E 
        C D E 
        B C D E 
        A B C D E
    */
    for(int i=0;i<n;i++){
        char ch = 'A'+n-i-1;
        for(int j=0;j<=i;j++){
            std::cout<<ch++<<" ";
        }
        std::cout<<"\n";
    }
}

void pattern19(int n){
    /*
        **********
        ****  ****
        ***    ***
        **      **
        *        *
        *        *
        **      **
        ***    ***
        ****  ****
        **********
    */
    int total_row_count = 2*n;
    int space=0;
    for(int i=0;i<total_row_count;i++){
        if(i<(total_row_count/2)){
            //for stars
            for(int j=0;j<n-i;j++){
                std::cout<<"*";
            }
            //for space
            for(int j=0;j<space;j++){
                std::cout<<" ";
            }
            //for stars
            for(int j=0;j<n-i;j++){
                std::cout<<"*";
            }
            space=space+2;
        }else{
            space=space-2;
            //for stars
            for(int j=0;j<i-n+1;j++){
                std::cout<<"*";
            }
            //for space
            for(int j=0;j<space;j++){
                std::cout<<" ";
            }
            //for stars
            for(int j=0;j<i-n+1;j++){
                std::cout<<"*";
            }
        }
        std::cout<<"\n";
    }
}

void pattern20(int n){
    /*
        *        *
        **      **
        ***    ***
        ****  ****
        **********
        ****  ****
        ***    ***
        **      **
        *        *
    */
    int total_row_count = 2*n-1;
    for(int i=0;i<total_row_count;i++){
        if(i<n){
            //for stars
            for(int j=0;j<=i;j++){
                std::cout<<"*";
            }
            //for space
            for(int j=0;j<2*(n-i)-2;j++){
                std::cout<<" ";
            }
            //for stars
            for(int j=0;j<=i;j++){
                std::cout<<"*";
            }
        }else{
            //for stars
            for(int j=0;j<2*n-i-1;j++){
                std::cout<<"*";
            }
            //for space
            for(int j=0;j<2*(i-n)+2;j++){
                std::cout<<" ";
            }
            //for stars
            for(int j=0;j<2*n-i-1;j++){
                std::cout<<"*";
            }
        }
        std::cout<<"\n";
        
    }
}

void pattern21(int n){
    /*
        *****
        *   *
        *   *
        *   *
        *****
    */
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0 || j==0 || i==n-1 || j==n-1){
                std::cout<<"*";
            }else{
                std::cout<<" ";
            }
        }
        std::cout<<"\n";
    }
}

void pattern22(int n){
    /*
        4444444
        4333334
        4322234
        4321234
        4322234
        4333334
        4444444
    */
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top = i;
            int left = j;
            int right = (2*n-2)-j;
            int down = (2*n-2)-i;
            std::cout<<(n-std::min(std::min(top,down),std::min(left,right)));
        }
        std::cout<<"\n";
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
    // pattern10(n);
    // pattern11(n);
    // pattern12(n-1);
    // pattern13(n);
    // pattern14(n);
    // pattern15(n);
    // pattern16(n);
    // pattern17(n-1);
    // pattern18(n);
    // pattern19(n);
    // pattern20(n);
    // pattern21(n);
    pattern22(n-1);

    std::cout<<"-----------------\n";
    return 0;
}
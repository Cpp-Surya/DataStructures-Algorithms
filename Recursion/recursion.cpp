#include <iostream>
#include <vector>
#include <string>

//Print first n natural numbers increasing order 1,2,3....n
void firstNIncreasing(int i, int n){
    if(i>n){
        return;
    }else{
        std::cout<<i<<"\n";
        firstNIncreasing(i+1,n);
    }
}

//Print first n natural numbers decreasing order n....3,2,1
void firstNDecreasing(int i, int n){
    if(i<1){
        return;
    }else{
        std::cout<<i<<"\n";
        firstNDecreasing(i-1,n);
    }
}

//Print first n natural numbers increasing order 1,2,3...n(backtracking)
void firstNIncreasingbt(int i,int n){
    if(i<1){
        return;
    }else{
        firstNIncreasingbt(i-1,n);
        std::cout<<i<<"\n";
    }
}

//Print first n natural numbers decreasing order n...3,2,1(backtracking)
void firstNDecreasingbt(int i, int n){
    if(i>n){
        return;
    }else{
        firstNDecreasingbt(i+1,n);
        std::cout<<i<<"\n";
    }
}

//Sum of first n natural numbers[parameterised way]
void SumOfNNumbers(int i, int sum){
    if(i==0){
        std::cout<<sum<<"\n";
    }else{
        SumOfNNumbers(i-1,sum+i);
    }
}

//Sum of first n natural numbers[function way]
int SumOfNNumbersF(int n){
    if(n==1){
        return 1;
    }else{
        return n + SumOfNNumbersF(n-1);
    }
}

//Reverse array using recursion[Two pointers]
void ReverseArrayTwoP(std::vector<int>& v, int left, int right){
    if(left>=right){
        return;
    }else{
        std::swap(v[left],v[right]);
        left++,right--;
        ReverseArrayTwoP(v,left,right);
    }
}

//Reverse of array using recursion[Single Pointer]
void ReverseArraySingleP(std::vector<int>& v, int i){
    if(i>=v.size()/2){
        return;
    }else{
        std::swap(v[i],v[v.size()-i-1]);
        ReverseArraySingleP(v,i+1);
    }
}

//Checking string is a Palindrome using recursion
bool IsStringPalindrome(std::string s,int i){
    if(i>=s.size()/2){
        return true;
    }
    if(std::tolower(s[i]) != std::tolower(s[s.size()-i-1])){
        return false;
    }else{
        return IsStringPalindrome(s,i+1);
    }
}

//Fibonacci series using recursion
int Fib(int n){
    if(n<=1){
        return 1;
    }else{
        return Fib(n-1) + Fib(n-2);
    }
}


int main()
{
    // firstNIncreasing(1,5);
    // firstNDecreasing(5,5);
    // firstNIncreasingbt(5,5);
    // firstNDecreasingbt(1,5);
    // SumOfNNumbers(3,0);//sum of first 3 natural numbers
    // std::cout<<SumOfNNumbersF(3)<<"\n";//sum of first 3 natural numbers
    // std::vector<int> v = {1,6,2,9,4,8};
    // //int left=0,right=v.size()-1;
    // //ReverseArrayTwoP(v,left,right);
    // //ReverseArraySingleP(v,0);
    // for(int i=0;i<v.size();i++){
    //     std::cout<<v[i]<<" ";
    // }
    // std::cout<<"\n";
    // std::cout<<std::boolalpha<<IsStringPalindrome("Madam",0)<<std::endl;
    // std::cout<<IsStringPalindrome("Non",0)<<std::endl;
    // std::cout<<IsStringPalindrome("None",0)<<std::endl;
    std::cout<<Fib(5)<<std::endl;

    return 0;
}
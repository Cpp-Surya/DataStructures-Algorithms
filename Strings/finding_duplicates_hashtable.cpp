#include <iostream>

int main(){
    char A[] = "finding";
    int hashtable_alphabetes[26]={0};
    for(int i=0;A[i]!='\0';i++){
        hashtable_alphabetes[A[i]-97]++;
    }

    for(int i=0;i<26;i++){
        if(hashtable_alphabetes[i]>1){
            std::cout<<"finding duplicates using hashtable: "<<static_cast<char>(i+97)<<"\n";
        }
    }
    return 0;
}
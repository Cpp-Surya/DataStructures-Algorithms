#include<iostream>

void Perm(char str[],int k){
    static int A[10];
    static char res[10];
    int i;
    if(str[k] == '\0'){
        res[k] = '\0';
        std::cout<<res<<"\n";
    }else{
        for(i=0;str[i]!='\0';i++){
            if(A[i]==0){
                res[k]=str[i];
                A[i]=1;
                Perm(str,k+1);
                A[i]=0;
            }
        }
    }
}

int main(){
    char str[] = "ABC";
    //Total no of combinations will be n!~3!
    Perm(str,0);
    return 0;
}
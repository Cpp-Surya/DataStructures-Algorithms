#include<iostream>
#include<algorithm>

int LengthOfString(char s[]){
    int i=0;
    for(i=0;s[i]!='\0';i++);
    //while(s[i]!=0){i++;};//using while loop
    return i;
}

void PermUsingSwap(char str[],int l,int h){
    int i;
    if(l==h){
        std::cout<<str<<"\n";
    }else{
        for(i=l;i<=h;i++){
            std::swap(str[l],str[i]);
            PermUsingSwap(str,l+1,h);
            std::swap(str[l],str[i]);
        }
    }
}

int main(){
    std::cout<<"Permutations using swap\n";
    char str[]="ABC";
    int l=0,h=LengthOfString(str)-1;
    PermUsingSwap(str,l,h);
    return 0;
}
#include<iostream>

int main(){
    char s[] = "finding";
    int H=0,x=0;
    //H is a 4byte(32-bit) integer which can store all alphabates
    //x is a helper variable used to set bits on and finds any bit is off
    for(int i=0;s[i]!='\0';i++){
        x=1;
        x=x<<(s[i]-97);
        if((H&x)>0){
            std::cout<<"finding duplicates using bitwise: "<<s[i]<<"\n";
        }else{
            H=H|x;
        }
    }
    return 0;
}
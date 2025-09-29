#include<iostream>

bool valid(char s[]){
    for(int i=0;s[i]!='\0';i++){
        if(!(s[i]>='a' && s[i]<='z')
        && !(s[i]>='A' && s[i]<='Z')
        && !(s[i]>='0' && s[i]<='9')){
            return false;
        }
    }
    return true;
}

int main(){
    char valid_str[]="Test123";
    char invalid_str[]="Test@123";
    valid(valid_str) ? std::cout<<"valid string\n" : std::cout<<"Invalid string\n";
    valid(invalid_str) ? std::cout<<"valid string\n" : std::cout<<"Invalid string\n";
    return 0;
}
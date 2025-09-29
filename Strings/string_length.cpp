#include <iostream>

int LengthOfString(char s[]){
    int i=0;
    for(i=0;s[i]!='\0';i++);
    //while(s[i]!=0){i++;};//using while loop
    return i;
}

int main()
{
    char name[10] = {'J','o','h','n','\0'};//string ending with null character
    std::cout<<name<<"\n";
    std::cout<<"Length of name str: "<<LengthOfString(name)<<"\n";
    return 0;
}
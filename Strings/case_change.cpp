#include <iostream>

void ConvertToUpperCase(char s[]){
    for(int i=0;s[i]!='\0';i++){
        //only convert lowercase letters to uppercase letters
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i]-32;
        }
    }
}

void ConvertToLowerCase(char s[]){
    for(int i=0;s[i]!='\0';i++){
        //only convert uppercase letters to lowercase letters
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i]+32;
        }
    }
}

void ToggleCase(char s[]){
    //change upper to lower and vice-versa
    for(int i=0;s[i]!='\0';i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            s[i] = s[i]-32;
        }else if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = s[i]+32;
        }
    }
}

int main()
{
    char lower[] = "test lower case function";
    char upper[] = "TEST UPPER CASE FUNCTION";
    ConvertToUpperCase(lower);
    ConvertToLowerCase(upper);
    std::cout<<"Converted to Upper: "<<lower<<"\n";
    std::cout<<"Converted to Lower: "<<upper<<"\n";
    char mixed[] = "This Is Testing";
    ToggleCase(mixed);
    std::cout<<"mixed case: "<<mixed<<"\n";
    return 0;
}
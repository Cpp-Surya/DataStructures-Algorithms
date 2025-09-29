#include <iostream>

int VowelCount(char s[]){
    int vcount=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E'
        || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O'
        || s[i] == 'u' || s[i] == 'U'){
            vcount++;
        }
    }
    return vcount;
}

int ConsonantCount(char s[]){
    int ccount=0;
    for(int i=0;s[i]!='\0';i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            if(s[i] != 'a' && s[i] != 'A' && s[i] != 'e' && s[i] != 'E'
            && s[i] != 'i' && s[i] != 'I' && s[i] != 'o' && s[i] != 'O'
            && s[i] != 'u' && s[i] != 'U'){
                ccount++;
            }
        }
    }
    return ccount;
}

int WordCount(char s[]){
    int wcount=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i] == ' ' && s[i-1] != ' '){
            wcount++;
        }
    }
    return wcount+1;
}

int main()
{
    char s10[] = "Name is test";
    std::cout<<"vowel count: "<<VowelCount(s10)<<"\n";
    std::cout<<"consonant count: "<<ConsonantCount(s10)<<"\n";
    std::cout<<"word count: "<<WordCount(s10)<<"\n";
    return 0;
}
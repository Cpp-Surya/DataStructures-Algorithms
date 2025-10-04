#include <iostream>

int LengthOfString(char s[]){
    int i=0;
    for(i=0;s[i]!='\0';i++);
    //while(s[i]!=0){i++;};//using while loop
    return i;
}

void CompareTwoStrings(char A[],char B[]){
    int i=0,j=0;
    for(i=0,j=0; A[i]!='\0' && B[j]!='\0'; i++,j++){
        if(A[i] != B[j]){
            break;
        }
    }

    if(A[i] == B[j]){
        std::cout<<"Equal\n";
    }else if(A[i]<B[j]){
        std::cout<<"Smaller\n";
    }else{
        std::cout<<"Larger\n";
    }
}

bool IsStringPalindrome(char s[]){
    //Reverse string
    char reversed_str[LengthOfString(s)+1];
    int i = LengthOfString(s)-1,j=0;
    for(i=LengthOfString(s)-1,j=0;i>=0;i--,j++){
        reversed_str[j] = s[i];
    }
    reversed_str[j]='\0';

    //Compare two strings
    i=0,j=0;
    for(i=0,j=0;s[i]!='\0'&&reversed_str[j]!='\0';i++,j++){
        if(s[i]!=reversed_str[j]){
            return false;
        }
    }
    return true;
}

bool IsStringPalindromeTwoPointers(char s[]){
    int i=0,j=LengthOfString(s)-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++,j--;
    }
    return true;
}

int main()
{
    char A[] = "painting";
    char B[] = "painter";
    CompareTwoStrings(A,B);
    char s1[] = "testing";
    char s2[] = "testing";
    CompareTwoStrings(s1,s2);
    char s3[] = "new";
    char s4[] = "newtest";
    CompareTwoStrings(s3,s4);
    //char palindrome_str[]="madam";
    //char palindrome_str[]="gsfsf";
    char palindrome_str[] = "lirril";
    if(IsStringPalindrome(palindrome_str))
        std::cout<<"Palindrome\n";
    else
        std::cout<<"Not Palindrome\n";

    if(IsStringPalindromeTwoPointers(palindrome_str))
        std::cout<<"Palindrome\n";
    else
        std::cout<<"Not Palindrome\n";
    
    return 0;
}
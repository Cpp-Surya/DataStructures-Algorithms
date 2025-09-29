#include <iostream>

int main()
{
    char s = 'A';//character variable
    std::cout<<s<<"\n";
    s=66;
    std::cout<<s<<"\n";
    char s1[5] = {'T','E','S','T','S'};//character array
    for(int i=0;i<5;i++)
        std::cout<<s1[i]<<" ";
    std::cout<<"\n";
    char s2[] = {'H','e','l','l','o'};//character array
    for(int i=0;i<5;i++)
        std::cout<<s2[i]<<" ";
    std::cout<<"\n";
    return 0;
}

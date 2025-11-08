#include<iostream>
#include<algorithm>
#include<vector>

//brute force
void move_zeros_to_end_brute(std::vector<int>& v){
    int n=v.size();
    std::vector<int> non_zero_vec;//lets say x non zero elements. space O(x)
    for(auto& num : v){
        if(num != 0){
            non_zero_vec.push_back(num);
        }
    }//time O(n)

    int i;
    for(i=0;i<non_zero_vec.size();i++){
        v[i]=non_zero_vec[i];
    }//time O(x)

    for(;i<n;i++){
        v[i] = 0;
    }//time O(n-x)
    /*
        Total Time complexity --> O(n+x+n-x) --> O(2n)
        Total space complexity --> O(x)
    */
}

void move_zeros_to_end_opt(std::vector<int>& v){
    int n=v.size();
    int i=0;
    while(i<n && v[i]!=0){
        i++;
    }//find first zero
    int j=i+1;
    while(j<n){
        if(v[j]!=0){
            std::swap(v[i],v[j]);
            i++;
        }
        j++;
    }
    /*
        Total Time complexity --> O(n)
        Total space complexity --> O(1)
    */  
}

int main(){
    std::vector<int> v{1,2,0,0,5,1,0,2,0,19,23,0};
    //move_zeros_to_end_brute(v);
    move_zeros_to_end_opt(v);
    for(auto& num : v){
        std::cout<<num<<" ";
    }
    std::cout<<'\n';

    return 0;
}
#include<iostream>
#include<vector>

bool is_array_sorted(std::vector<int> v){
    for(int i=0;i<v.size()-1;i++){
        if(v[i]>v[i+1]){
            return false;
        }
    }//O(n)
    return true;
}

int main(){
    std::vector<int> v1{1,4,6,8,22},v2{54,55,78,12,67,98};
    std::cout<<std::boolalpha<<is_array_sorted(v1)<<"\n"<<is_array_sorted(v2)<<"\n";
    return 0;
}
#include<iostream>
#include<vector>

int remove_duplicates(std::vector<int>& v){
    if(v.size() == 0){
        return 0;
    }
    if(v.size()==1){
        return 1;
    }
    int i=0,j=1;
    while(j<v.size()){
        if(v[i]!=v[j]){
            v[i+1] = v[j];
            i = i+1;
        }
        j++;
    }
    return i+1;
}

int main(){
    std::vector<int> v1{3,4,5,5,6,6,6,6,7,9};
    std::cout<<"No of unique elements: "<<remove_duplicates(v1)<<"\n";
    for(auto& e : v1){
        std::cout<<e<<" ";
    }
    std::cout<<"\n";
    std::vector<int> v2{1};
    std::cout<<"No of unique elements: "<<remove_duplicates(v2)<<"\n";
    for(auto& e : v2){
        std::cout<<e<<" ";
    }
    std::cout<<"\n";
    std::vector<int> v3{1,2,3,4};
    std::cout<<"No of unique elements: "<<remove_duplicates(v3)<<"\n";
    for(auto& e : v3){
        std::cout<<e<<" ";
    }
    std::cout<<"\n";
    std::vector<int> v4{};
    std::cout<<"No of unique elements: "<<remove_duplicates(v4)<<"\n";
    for(auto& e : v4){
        std::cout<<e<<" ";
    }
    std::cout<<"\n";
    return 0;
}
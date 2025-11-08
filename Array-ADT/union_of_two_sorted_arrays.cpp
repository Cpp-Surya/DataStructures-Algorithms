#include<iostream>
#include<vector>
#include<set>

//brute force
std::vector<int> union_of_arrays_brute(std::vector<int> v1, std::vector<int> v2){
    std::set<int> unique_elements;//space O(n1+n2)
    int n1 = v1.size(),n2 = v2.size();
    for(int i=0;i<n1;i++){
        unique_elements.insert(v1[i]);
    }//time O(n1)

    for(int i=0;i<n2;i++){
        unique_elements.insert(v2[i]);
    }//time O(n2)
    std::vector<int> result;//space O(n1+n2)
    result.reserve(unique_elements.size());
    for(auto&e : unique_elements){
        result.push_back(e);
    }//time O(n1+n2)
    return result;
    /*
        Total time complexity --> O(n1+n2+n1+n2) -> O(2(n1+n2))
        Total space complexity --> O(n1+n2+n1+n2) -> O(2(n1+n2))
    */
}

//optimal
std::vector<int> union_of_arrays_opt(std::vector<int> v1, std::vector<int> v2){
    std::vector<int> result;//space O(n1+n2)
    int i=0,j=0,n1 = v1.size(),n2 = v2.size();
    while(i<n1 && j<n2){
        if(v1[i] < v2[j]){
            if(result.size()==0 || result.back() != v1[i]){
                result.push_back(v1[i]);
            }
            i++;
        }else{
            if(result.size()==0 || result.back() != v2[j]){
                result.push_back(v2[j]);
            }
            j++;
        }
    }//time O(n1) or O(n2)

    while(i<n1){
        if(result.size()==0 || result.back() != v1[i]){
                result.push_back(v1[i]);
        }
        i++;
    }//time remaining k elements O(k)

    while(j<n2){
        if(result.size()==0 || result.back() != v2[j]){
                result.push_back(v2[j]);
        }
        j++;
    }//time remaining k elements O(k)
    return result;
    /*
        Total complexity --> O(n1+n2)
        Space complexity --> O(n1+n2)
    */
}

int main(){
    std::vector<int> v1{1,4,6,6,8,8,8,9}, v2{2,3,3,4,5,5};
    // auto result = union_of_arrays_brute(v1,v2);
    auto result = union_of_arrays_opt(v1,v2);
    for(auto& e:result){
        std::cout<<e<<" ";
    }
    std::cout<<'\n';
    return 0;
}
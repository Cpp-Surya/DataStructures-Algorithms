#include <iostream>
#include<vector>
#include<map>

int longest_sub_array_brute(std::vector<int> v,int k){
    int n=v.size();
    int max_length{0};
    for(int i=0;i<n;i++){//O(n)
        int sum =0;
        for(int j=i;j<n;j++){//O(n-i)
            sum = sum+v[j];
            if(sum == k){
                max_length = std::max(max_length,j-i+1);
                break;
            }else if(sum > k){
                break;
            }
        }
    }//Time complexity O(n*(n-i))~O(n^2), Space complexity O(1)
    return max_length;
}

int longest_sub_array_better(std::vector<int> v,int k){//works for both positive and negative nums in array
    int n=v.size();
    int max_length{0};
    int sum=0;
    std::map<int,int> pre_sum_map;
    for(int i=0;i<n;i++){
        sum = sum+v[i];
        if(sum == k){
            max_length = std::max(max_length,i+1);
        }
        int rem = sum-k;
        if(pre_sum_map.find(rem) != pre_sum_map.end()){
            int length = i-pre_sum_map[rem];
            max_length = std::max(max_length,length);
        }
        if(pre_sum_map.find(sum) == pre_sum_map.end()){
            pre_sum_map[sum] = i;
        }
    }//Time complexity O(nlogn), Space complexity O(n)
    return max_length;
}

int longest_sub_array_optim(std::vector<int> v,int k){
    int n=v.size();
    int max_length{0},i=0,j=0;
    int sum=0;
    while(j<n){
        sum = sum+v[j];
        while(i<=j && sum>k){
            sum = sum - v[i];
            i++;
        }
        if(sum == k){
            max_length = std::max(max_length,j-i+1);
        }
        j++;
    }//Time complexity O(2n), Space complexity O(1)
    return max_length;
}

int main()
{
    std::vector<int> v{1,2,3,1,1,6,1,7,10,2,5,7};
    int k = 7;
    //auto max_len=longest_sub_array_brute(v,k);
    // auto max_len=longest_sub_array_better(v,k);
    auto max_len= longest_sub_array_optim(v,k);
    if(max_len !=0 ){
        std::cout<<"max: "<<max_len<<"\n";
    }else{
        std::cout<<"no sub array exist of length "<<k<<'\n';
    }

    return 0;
}
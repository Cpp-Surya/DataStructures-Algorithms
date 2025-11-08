#include <iostream>
#include <vector>

//Brute Force
void left_rotate_brute(std::vector<int>& v, int k){
    int n = v.size();
    if(n == 0 || n == 1)
        return;
    k=k%n;
    std::vector<int> temp{v.begin(),v.begin()+k};//stores first k elements. space: O(k), time O(k)
    int i;
    for(i=k;i<n;i++){//time O(n-k)
        v[i-k] = v[i];
    }
    for(i=0;i<temp.size();i++){//time O(k)
        v[n-k+i] = temp[i];
    }
    /*
        Total time complexity
        O(k+n-k+k) --> O(n+k)
        Total space complexity
        O(k)
    */
}

void right_rotate_brute(std::vector<int>& v, int k){
    int n=v.size();
    if(n == 0 || n == 1)
        return;
    k=k%n;
    std::vector<int> temp{v.end()-k,v.end()};//stores last k elements. space: O(k), time O(k)
    int i;
    for(i=n-k-1;i>=0;i--){//time O(n-k)
        v[i+k] = v[i];
    }
    for(i=0;i<k;i++){//time O(k)
        v[i] = temp[i];
    }
    /*
        Total time complexity
        O(k+n-k+k) --> O(n+k)
        Total space complexity
        O(k)
    */
}

//Optimal
void reverse_vec(std::vector<int>& v,int start, int end){
    while(start<end){
        int temp = v[start];
        v[start] = v[end];
        v[end] = temp;
        start++,end--;
    }
}
void left_rotate_opt(std::vector<int>& v, int k){
    int n=v.size();
    if(n == 0 || n == 1)
        return;
    k=k%n;
    reverse_vec(v,0,n-1);//Time complexity O(n)
    reverse_vec(v,0,n-k-1);//Time complexity O(n-k)
    reverse_vec(v,n-k,n-1);//Time complexity O(k)
    /*
        Total time complexity
        O(n+n-k+k) --> O(2n)
        Total space complexity
        O(1) no extra space
    */
}

void right_rotate_opt(std::vector<int>& v, int k){
    int n=v.size();
    if(n == 0 || n == 1)
        return;
    k=k%n;
    reverse_vec(v,0,n-1);//Time complexity O(n)
    reverse_vec(v,0,k-1);//Time complexity O(k)
    reverse_vec(v,k,n-1);//Time complexity O(n-k)
    /*
        Total time complexity
        O(n+k+n-k) --> O(2n)
        Total space complexity
        O(1) no extra space
    */
}

int main(){
    //Left rotate array by k places
    std::vector<int> v{1,2,3,4,5,6,7};
    int k = 2;
    //left_rotate_brute(v,k);
    //left_rotate_opt(v,k);
    //right_rotate_brute(v,k);
    right_rotate_opt(v,k);
    for(auto& e : v){
        std::cout<<e<<" ";
    }
    std::cout<<'\n';

    return 0;
}
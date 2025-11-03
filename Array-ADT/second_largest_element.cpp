#include<iostream>
#include<vector>

int second_largest_element(std::vector<int> v){
    int largest = v[0], second_largest = INT_MIN;
    for(int i=1;i<v.size();i++){
        if(v[i] > largest){
            second_largest = largest;
            largest = v[i];
        }else if(v[i] < largest && v[i] > second_largest){
            second_largest = v[i];
        }
    }//O(n)
    return second_largest;
}

int second_smallest_element(std::vector<int> v){
    int smallest = v[0], second_smallest = INT_MAX;
    for(int i=1;i<v.size();i++){
        if(v[i] < smallest){
            second_smallest = smallest;
            smallest = v[i];
        }else if(v[i]>smallest && v[i]<second_smallest){
            second_smallest = v[i];
        }
    }//O(n)
    return second_smallest;
}

int main(){
    std::vector<int> v{0,1,65,85,2,34,17,98};
    std::cout<<"Second largest: "<<second_largest_element(v)<<"\n";//85
    std::cout<<"Second smallest: "<<second_smallest_element(v)<<"\n";//1
    return 0;
}
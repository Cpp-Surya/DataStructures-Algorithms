#include <iostream>
#include <algorithm>
#include <vector>

//Select minimum value from array and swap with first position[of each sub array]
void selection_sort(std::vector<int>& v){
    for(int i=0;i<v.size()-1;i++){
        int min = i;
        for(int j=i+1;j<v.size();j++){
            if(v[j] < v[min]){
                min = j;
            }
        }
        std::swap(v[i],v[min]);
    }
}

//Moves max element to last for each iteration by doing adjacent swaps, and resize array for each iteration
void bubble_sort(std::vector<int>& v){
    for(int i=v.size()-1;i>=1;i--){
        bool isswapped{false};
        for(int j=0;j<i;j++){
            if(v[j] > v[j+1]){
                std::swap(v[j],v[j+1]);
                isswapped = true;
            }
        }
        if(!isswapped){
            //array is already swapped
            break;
        }
    }
}

//Check the current element with previous element and does swap
void insertion_sort(std::vector<int>& v){
    for(int i=0;i<v.size()-1;i++){
        for(int j=i+1;j>0;j--){
            if(v[j]>v[j-1]){
                //if current value is greater than previous then its already sorted
                break;
            }
            //if current value is less than previous swap
            std::swap(v[j],v[j-1]);
        }
    }
}

void merge_array(std::vector<int>& v,int low, int mid, int high){
    std::vector<int> temp;
    temp.reserve(v.size());
    int left = low, right = mid+1;
    while(left<=mid && right<=high){
        if(v[left]<=v[right]){
            temp.push_back(v[left]);
            left++;
        }else{
            temp.push_back(v[right]);
            right++;
        }
    }

    //if any remaining elements
    while(left<=mid){
        temp.push_back(v[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(v[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        v[i] = temp[i-low];
    }
}

// Divides the array into half till single element then merges
void merge_sort(std::vector<int>& v,int low, int high){
    if(low >= high){
        return;
    }
    int mid = (low+high)/2;
    merge_sort(v,low,mid);
    merge_sort(v,mid+1,high);
    merge_array(v,low,mid,high);
}

int partition(std::vector<int>& v,int low, int high){
    int pivot = v[low];
    int i=low,j=high;
    while(i<j){
        while(v[i]<=pivot && i<= high-1){
            i++;
        }
        while(v[j]>pivot && j>= low+1){
            j--;
        }
        if(i<j){
            std::swap(v[i],v[j]);
        }
    }
    std::swap(v[low],v[j]);
    return j;    
}

//Picks up a pivot and swaps smaller elements to its left and larger to its right
void quick_sort(std::vector<int>& v, int low, int high){
    if(low < high){
        int partition_index = partition(v,low,high);
        quick_sort(v,low,partition_index-1);
        quick_sort(v,partition_index+1,high);
    }
}

int main(){
    std::vector<int> v{45,12,37,9,21,37,89,33,33};
    // selection_sort(v);
    // bubble_sort(v);
    // insertion_sort(v);
    // merge_sort(v,0,v.size()-1);
    quick_sort(v,0,v.size()-1);
    for(auto& e : v){
        std::cout<<e<<" ";
    }
    std::cout<<"\n";
}
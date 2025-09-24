#include <iostream>
#include <algorithm>

struct Array{
    int A[10];
    int length;
    int max_size;
};

void display(Array arr){
    if(arr.length > 0){
        std::cout<<"Array elements: ";
        for(int i=0;i<arr.length;i++){
            std::cout<<arr.A[i]<<" ";
        }
        std::cout<<"\n";
    }else{
        std::cout<<"Array is empty\n";
    }
}

void append_element(Array& arr, int value){
    //appends element at end of an array
    if(arr.length < arr.max_size){//checks for free space
        arr.A[arr.length] = value;
        arr.length++;
    }else{
        std::cerr<<"No space left to add element\n";
    }
}

void insert_element(Array& arr, int index, int value){
    if(index >= 0 && index <= arr.length && arr.length < arr.max_size){
        for(int i = arr.length;i>index;i--){
            arr.A[i] = arr.A[i-1];
        }
        arr.A[index] = value;
        arr.length++;
    }else{
        std::cerr<<"Index out of bound or no free space left\n";
    }
}

void delete_element(Array& arr,int index){
    if(index>=0 && index<arr.length){
        for(int i = index;i < arr.length-1;i++){
            arr.A[i] = arr.A[i+1];
        }
        arr.length--;
    }else{
        std::cerr<<"Deletion requested for out of bound address\n";
    }
}

int linear_search(Array arr,int target){
    if(arr.length <= 0){
        std::cerr<<"Array is empty, no search can be done\n";
        return -1;
    }
    for(int i=0; i<arr.length; i++){
        if(arr.A[i] == target){
            return i;
        }
    }
    return -1;
}

int linear_search_by_transposition(Array& arr, int target){
    if(arr.length <= 0){
        std::cerr<<"Array is empty, no search can be done\n";
        return -1;
    }
    if(arr.A[0] == target){
        return 0;
    }
    for(int i=1; i<arr.length; i++){
        if(arr.A[i] == target){
            std::swap(arr.A[i],arr.A[i-1]);//swaps element with previous element, so next time search will be easy
            return i-1;
        }
    }
    return -1;
}

int linear_search_by_move_front(Array& arr, int target){
    if(arr.length <= 0){
        std::cerr<<"Array is empty, no search can be done\n";
        return -1;
    }
    if(arr.A[0] == target){
        return 0;
    }
    for(int i=1;i<arr.length;i++){
        if(arr.A[i] == target){
            std::swap(arr.A[0],arr.A[i]);
            return 0;
        }
    }
    return -1;
}

int binary_search(Array arr, int target){
    if(arr.length<=0){
        std::cerr<<"Array is empty, no search can be done\n";
        return -1;
    }
    if(arr.A[0] == target){
        return 0;
    }
    int low = 0,high = arr.length;
    while(low <= high){
        int mid = (low+high)/2;
        if(arr.A[mid] == target){
            return mid;
        }else if(arr.A[mid] > target){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return -1;
}

int get(Array arr,int index){
    //Get element by index
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}

void set(Array& arr,int index,int value){
    //Sets element at given index
    if(index>=0 && index<arr.length){
        arr.A[index] = value;
    }else{
        std::cerr<<"Requested invalid address\n";
    }
}

int max(Array arr){
    int max = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

int min(Array arr){
    int min = arr.A[0];
    for(int i=1;i<arr.length;i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

int sum(Array arr){
    int s=0;
    for(int i=0;i<arr.length;i++){
        s = s+arr.A[i];
    }
    return s;
}

float avg(Array arr){
    return (float)sum(arr)/arr.length;
}

void swap_f(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void reverse_array(Array& arr){
    int left=0,right=arr.length-1;
    while(left<right){
        swap_f(&arr.A[left],&arr.A[right]);
        left++;
        right--;
    }
}

void left_shift(Array& arr){
    int i;
    for(i=0;i<arr.length-1;i++){
        arr.A[i] = arr.A[i+1];
    }
    arr.A[i] = 0;
}

void right_shift(Array& arr){
    int i;
    for(i=arr.length-1;i>0;i--){
        arr.A[i] = arr.A[i-1];
    }
    arr.A[i] = 0;
}

void left_rotate(Array& arr){
    int i,temp = arr.A[0];
    for(i=0;i<arr.length-1;i++){
        arr.A[i] = arr.A[i+1];
    }
    arr.A[i] = temp;
}

void right_rotate(Array& arr){
    int i,temp = arr.A[arr.length-1];
    for(i=arr.length-1;i>0;i--){
        arr.A[i] = arr.A[i-1];
    }
    arr.A[i] = temp;
}

void insert_in_a_sorted_array(Array& arr, int value){
    if(arr.length == arr.max_size){
        std::cerr<<"No space left for insertion\n";
        return;
    }
    int i = arr.length-1;
    while(i>=0 && arr.A[i] > value){
        arr.A[i+1] = arr.A[i];
        i--;
    }
    arr.A[i+1] = value;
    arr.length++;
}

bool is_array_sorted(Array arr){
    for(int i=0;i<arr.length-1;i++){
        if(arr.A[i] > arr.A[i+1]){
            return false;
        }
    }
    return true;
}

void rearrange(Array& arr){
    int left=0,right=arr.length-1;
    while(left<right){
        while(arr.A[left] < 0){
            left++;
        }
        while(arr.A[right] >= 0){
            right--;
        }
        if(left<right){
            swap_f(&arr.A[left],&arr.A[right]);
        }
    }
}

Array* merge(Array arr1, Array arr2){
    Array* merged_arr = new Array();
    merged_arr->max_size = 10;
    int i,j,k;
    i=j=k=0;
    while(i<arr1.length && j<arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            merged_arr->A[k] = arr1.A[i];
            k++,i++,merged_arr->length++;
        }else{
            merged_arr->A[k] = arr2.A[j];
            k++,j++,merged_arr->length++;
        }
    }
    for(;i<arr1.length;i++){
        merged_arr->A[k] = arr1.A[i];
        k++,merged_arr->length++;
    }
    for(;j<arr2.length;j++){
        merged_arr->A[k] = arr2.A[j];
        k++,merged_arr->length++;
    }
    return merged_arr;
}

int main(){
    Array arr{{32,56,76,12,100},5,10};
    display(arr);
    append_element(arr,5);
    append_element(arr,18);
    display(arr);
    insert_element(arr,3,99);
    append_element(arr,121);
    insert_element(arr,0,300);
    display(arr);
    delete_element(arr,8);
    display(arr);
    delete_element(arr,-1);
    delete_element(arr,8);
    display(arr);
    std::cout<<"linear search 5 position: "<<linear_search(arr,5)<<"\n";
    std::cout<<"linear search 999 position: "<<linear_search(arr,999)<<"\n";
    std::cout<<"linear search by transpos 300 position: "<<linear_search_by_transposition(arr,300)<<"\n";
    display(arr);
    Array arr2{{1,2,3,4,5},5,10};
    std::cout<<"linear search by move front 3 position: "<<linear_search_by_move_front(arr2,3)<<"\n";
    display(arr2);
    Array arr3{{},0,7};
    std::cout<<"linear search by move front 100 position: "<<linear_search_by_move_front(arr3,100)<<"\n";
    Array arr4{{12,24,31,42,55,61,72},7,10};
    std::cout<<"binary search 72 position: "<<binary_search(arr4,72)<<"\n";
    std::cout<<"binary search 12 position: "<<binary_search(arr4,12)<<"\n";
    std::cout<<"binary search 55 position: "<<binary_search(arr4,55)<<"\n";
    std::cout<<"binary search 5999 position: "<<binary_search(arr4,5999)<<"\n";
    Array arr5{{56,21,45,67,18},5,10};
    std::cout<<"get element at index 4: "<<get(arr5,2)<<"\n";
    set(arr5,2,999);
    display(arr5);
    std::cout<<"Max: "<<max(arr5)<<"\n";
    std::cout<<"Min: "<<min(arr5)<<"\n";
    std::cout<<"Sum: "<<sum(arr5)<<"\n";
    std::cout<<"Average: "<<avg(arr5)<<"\n";
    Array arr6{{67,12,45,82,17,43},6,10};
    // std::cout<<"Before swap\n";
    // display(arr6);
    // reverse_array(arr6);
    // display(arr6);
    // left_shift(arr6);
    // display(arr6);
    // right_shift(arr6);
    // display(arr6);
    // left_rotate(arr6);
    // display(arr6);
    // right_rotate(arr6);
    // display(arr6);
    // Array arr7{{1,29,22,35,41,58},6,10};
    // display(arr7);
    // insert_in_a_sorted_array(arr7,0);
    // display(arr7);
    // Array sorted_arr{{1,34,56,61,77},5,10};
    // Array unsorted_arr{{2,32,11,45},4,5};
    // std::cout<<"{1,34,56,61,77} is sorted: "<<std::boolalpha<<is_array_sorted(sorted_arr)<<"\n";
    // std::cout<<"{2,32,11,45} is sorted: "<<std::boolalpha<<is_array_sorted(unsorted_arr)<<"\n";
    Array mixed_arr{{-1,32,78,-98,56,-11,-56,23,14},9,9};
    display(mixed_arr);
    rearrange(mixed_arr);
    display(mixed_arr);
     Array sorted_arr1{{1,3,5,7,9},5,10};
    Array sorted_arr2{{2,4,6,8},4,10};
    Array* merged_arr = merge(sorted_arr1,sorted_arr2);
    std::cout<<"Merged array length: "<<merged_arr->length<<"\n";
    display(sorted_arr1);
    display(sorted_arr2);
    display(*merged_arr);
    delete merged_arr;
    return 0;
}
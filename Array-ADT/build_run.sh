#Clear
rm -rf build

#Create build
mkdir build && cd build

#Build exe
#g++ ../second_largest_element.cpp -o second_largest_element
#g++ ../check_array_is_sorted.cpp -o check_array_is_sorted
#g++ ../remove_duplicates.cpp -o remove_duplicates
#g++ ../rotate_array.cpp -o rotate_array
#g++ ../move_zeros_to_end.cpp -o move_zeros_to_end
# g++ ../union_of_two_sorted_arrays.cpp -o union_of_two_sorted_arrays
g++ ../longest_sub_array.cpp -o longest_sub_array

#Run exe
#./second_largest_element
#./check_array_is_sorted
#./remove_duplicates
#./rotate_array
#./move_zeros_to_end
# ./union_of_two_sorted_arrays
./longest_sub_array

#Exit and remove build
cd .. && rm -rf build

#Clear
rm -rf build

#Create build
mkdir build && cd build

#Build exe
g++ ../second_largest_element.cpp -o second_largest_element
g++ ../check_array_is_sorted.cpp -o check_array_is_sorted
g++ ../remove_duplicates.cpp -o remove_duplicates

#Run exe
./second_largest_element
./check_array_is_sorted
./remove_duplicates

#Exit and remove build
cd .. && rm -rf build

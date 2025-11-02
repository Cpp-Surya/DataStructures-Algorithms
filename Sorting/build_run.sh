#Clear
rm -rf build

#Create build
mkdir build && cd build

#Build exe
g++ ../sorting.cpp -o sorting

#Run exe
./sorting

#Exit and remove build
cd .. && rm -rf build

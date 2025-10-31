#Clear
rm -rf build

#Create build
mkdir build && cd build

#Build exe
g++ ../recursion.cpp -o recursion

#Run exe
./recursion

#Exit and remove build
cd .. && rm -rf build

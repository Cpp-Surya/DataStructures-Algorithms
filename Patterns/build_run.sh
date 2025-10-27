#Clear
rm -rf build

#Create build
mkdir build && cd build

#Build exe
g++ ../patterns.cpp -o patterns

#Run exe
./patterns

#Exit and remove build
cd .. && rm -rf build

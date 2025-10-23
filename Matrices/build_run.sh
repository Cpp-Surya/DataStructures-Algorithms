#Clear
rm -rf build

#Create build
mkdir build && cd build

#Build exe
g++ ../diagonal_matrix.cpp -o diagonal_matrix
g++ ../lower_triangular_matrix.cpp -o lower_triangular_matrix

#Run exe
./diagonal_matrix
./lower_triangular_matrix

#Exit and remove build
cd .. && rm -rf build

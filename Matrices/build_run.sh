#Clear
rm -rf build

#Create build
mkdir build && cd build

#Build exe
g++ ../diagonal_matrix.cpp -o diagonal_matrix
g++ ../lower_triangular_matrix.cpp -o lower_triangular_matrix
g++ ../upper_triangular_matrix.cpp -o upper_triangular_matrix
g++ ../symmetric_matrix.cpp -o symmetric_matrix
g++ ../tri_diagonal_matrix.cpp -o tri_diagonal_matrix
g++ ../toeplitz_matrix.cpp -o toeplitz_matrix

#Run exe
./diagonal_matrix
./lower_triangular_matrix
./upper_triangular_matrix
./symmetric_matrix
./tri_diagonal_matrix
./toeplitz_matrix

#Exit and remove build
cd .. && rm -rf build

#Clear
rm -rf build

#Create build
mkdir build && cd build

#Build exe
g++ ../strings.cpp -o strings
g++ ../string_length.cpp -o string_length
g++ ../case_change.cpp -o case_change
g++ ../vowel_consonant_word_count.cpp -o vowel_consonant_word_count
g++ ../validate_string.cpp -o validate_string
g++ ../compare_two_strings.cpp -o compare_two_strings
g++ ../finding_duplicates_hashtable.cpp -o finding_duplicates_hashtable
g++ ../finding_duplicates_bitwise.cpp -o finding_duplicates_bitwise
g++ ../permutations_for_string.cpp -o permutations_for_string
g++ ../permutations_for_string_swap.cpp -o permutations_for_string_swap

#Run exe
./strings
./string_length
./case_change
./vowel_consonant_word_count
./validate_string
./compare_two_strings
./finding_duplicates_hashtable
./finding_duplicates_bitwise
./permutations_for_string
./permutations_for_string_swap

#Exit and remove build
cd .. && rm -rf build

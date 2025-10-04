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

#Run exe
./strings
./string_length
./case_change
./vowel_consonant_word_count
./validate_string
./compare_two_strings

#Exit and remove build
cd .. && rm -rf build

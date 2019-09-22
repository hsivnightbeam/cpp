/*
  Chapter 1 (Arrays and Strings) Problem 4
  TODO: add tests
*/
#include <iostream>
#include <map>
#include <string>
#include <cctype>



// --method to check if the iStr is a permutation of a palindrome: does it in one pass
// --output: true iStr is permutation of a palindrome
bool sol1 (const std::string& iStr) {
    std::map<char, int> countChars;
    int size = 0;          //size of str without counting spaces
    int notPaired = 0;
    // we store the chars that we find with their counts, and the number of chars without counting whitespaces
    for (auto const& aChar : iStr) {
        if (aChar != ' ') {
            ++countChars[std::tolower(static_cast<unsigned char>(aChar))];
            if (countChars[aChar] % 2 == 1)
                ++notPaired;
            else
                --notPaired;
        }
    }
    return notPaired <= 1;   //could also do: return (size % 2 == 0) ? !notPaired : (notPaired == 1);
}

void countChars (std::map<char, int>& tableChars, const std::string& str, int& size) {
    // we store the chars that we find with their counts, and the number of chars without counting whitespaces
    for (auto const& aChar : str) {
        if (aChar != ' ') {
            ++tableChars[std::tolower(static_cast<unsigned char>(aChar))];
            ++size;
        }
    }
}

int evenCount (std::map<char, int>& tableChars, int size) {
    int unmatched = 0;
    bool isEven = ((size %2) == 0) ? true:false;
    for (auto const& el : tableChars) {
        if ((el.second % 2) != 0) {
           if ((isEven ||                // If is str is even length, we don't admit uneven chars
               (unmatched > 1))          // If is str is odd length, we don't admit more than one uneven char
              )
              return false;
           ++unmatched;
        }
    }
    return true;
}

// --method to check if the iStr is a permutation of a palindrome: does it in two passes
// --output: true iStr is permutation of a palindrome
bool sol2 (const std::string& str) {
    std::map<char, int> tableChars;
    int size = 0;          //size of str without counting spaces
    countChars (tableChars, str, size);
    return evenCount(tableChars, size);
}

// --returns a bit vector where bit is set 1 for unpaired Chars
int createBitVector(const std::string& str) {
    int bitVector = 0;
    for (auto const& aChar : str) {
        int mask = 1 << (aChar - ' ');
        bitVector ^= mask;
    }
    return bitVector; 
}

// --return true if only one bit is set to 1
bool checkExactlyOneBitSet(int bitVector) {
    return (bitVector & (bitVector - 1)) == 0;
}

// --method to check if the iStr is a permutation of a palindrome: does it with bitwise ops
// --output: true iStr is permutation of a palindrome
bool sol3 (const std::string& str) {
    int bitVector = createBitVector(str);
    return (bitVector == 0) ||                    //all the pair chars were paired
            checkExactlyOneBitSet(bitVector);     //a max of 1 char was unpaired
}


int main () {
    std::string inputStr;
    std::cout << "Please input string: " << std::endl;
    while (std::getline(std::cin, inputStr)) {
        std::cout << "Is Permutation of a palindrome? (onePass) " << sol1(inputStr) << std::endl;
        std::cout << "Is Permutation of a palindrome? (twoPass) " << sol2(inputStr) << std::endl;
        std::cout << "Is Permutation of a palindrome? (bitwise) " << sol3(inputStr) << std::endl;
        std::cout << "Please input string: " << std::endl;
    }
    return 0;
}

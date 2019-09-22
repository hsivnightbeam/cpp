/*
  Chapter 1 (Arrays and Strings) Problem 3
  TODO: add tests
*/

#include <iostream>
#include <string>


// method that counts number of whitespaces
// --returns the count of whitespaces in str
int countSpaces(const std::string& str, const int trueSize){
    int spaces = 0;
    const char WHITESPACE = ' ';
    for (int i = 0; i < trueSize; ++i) {
        if (str[i] == WHITESPACE)
           ++spaces;
    }
    return spaces;
}


// --Method that swaps whitespace with %20. Modifies iStr for the output
// --returns false if the operation can't be done due to lack of space in iStr
bool swapSpaces (std::string& iStr, const int trueSize) {
    // count whitespaces
    int spaces = countSpaces(iStr, trueSize);
    int final_pos = trueSize-1  + 2*spaces;
    //check that the str has enough space
    if (iStr.size() < final_pos)
        return false;
    for (int i = trueSize-1; i >= 0; --i) {
        if (iStr[i] != ' ') {
            iStr[final_pos] = iStr[i];
            --final_pos;
        }
        else {
            iStr[final_pos] = '0';
            iStr[final_pos-1] = '2';
            iStr[final_pos-2] = '%';
            final_pos -= 3;
        }
    }
    return true; 
}



int main () {
    std::string str("Hello World !  xxxxxxxx");  // x are for the additional space required
    int trueSize = 15;
    swapSpaces(str, trueSize);
    std::cout << str << std::endl;

    return 0;
}

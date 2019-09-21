/*
  Chapter 1 (Arrays and Strings) Problem 1: check if input string has all unique characters
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <string>
#include <vector>

// --assumption: iStr uses ASCII set
// --returns true if iStr has all unique chars
bool sol1 (const std::string& iStr) {
    if (iStr.size() > 128) return false;
    std::vector<bool> charPresent (128, false);

    for (auto const &el : iStr) {
        if (charPresent[el])
            return false;                         //this char has already been seen
        charPresent[el] = true;
    }
    return true;
}

// --assumption: iStr uses ASCII set
// --returns true if iStr has all unique chars
bool sol2(const std::string &iStr) {
    if (iStr.size() > 128) return false;
    std::unordered_set<char> chars(iStr.begin(), iStr.end());
    return (iStr.size() == chars.size());
}


// --assumption: iStr uses ASCII set
// --returns true if iStr has all unique chars
bool sol3(const std::string &iStr) {
    if (iStr.size() > 128) return false;
    std::string str = iStr;
    std::sort(str.begin(), str.end());       //quickSort is supposed to not be using additional memory
    for (std::string::const_iterator it = str.begin(); it < (str.end() - 1); it++) {          //str.size() - 1 is an error for if iStr has size 0
        if (*it == *(it+1))
            return false;
    }
    return true;
}

// --assumption: iStr uses ASCII set
// --returns true if iStr has all unique chars
//   error_method-> if long long does not have at least 5 bytes then we activate this, because we don't support at least 128 bits
bool sol4(const std::string& iStr, bool& error_method) {
    if (iStr.length() > 128) return false;
    if (sizeof(long long) < 5) {
        error_method = true;
        return false;
    }

    long long checker = 0;  //guaranteed to be 4 bytes
    // we iterate every character in the string and save the ones we have not seen,
    // if a char was already seen then we return
    for (auto const &my_iter : iStr) {
        long long val = my_iter;
        if ((( 1 << val) & checker) != 0 ){
            return false;
        }
        checker |= 1 << val;
    }
    return true;
}

// Some tests
// output: will return false if tests don't pass
bool doTestsPass() {
  std::vector<std::pair<std::string, bool>> tests = {
      {"", true},
      {"|asd", true},
      {"apple", false},
      {"racecars", false},
  };
  bool result = true;
  bool error_method = false;
  for (auto const &el : tests) {
      result &= sol1(el.first) == el.second;
      result &= sol2(el.first) == el.second;
      result &= sol3(el.first) == el.second;
      result &= (sol4(el.first, error_method) == el.second || error_method == true);
      if (error_method)
          std::cout << "checkIfUniqueCharsUsingIntBitwise failing because of sizeof(long) < 5 (bytes)";
  }
  return result;
}




int main () {
    if (doTestsPass())
        std::cout << "All tests pass" << std::endl;
    else
        std::cout << "There are test failures" << std::endl;

    std::string iStr;
    while ( std::cout << "Please input the string to check: " << std::endl && std::cin >> iStr) {
        std::cout << "Has unique characters (using vector): " << sol1(iStr) << std::endl;
        std::cout << "Has unique characters (using unordered_set): " << sol2(iStr) << std::endl;
        std::cout << "Has unique characters (using sort): " << sol3(iStr) << std::endl;
        bool errorMethod = false;
        std::cout << "Has unique characters (using bitwise with int): " << sol4(iStr, errorMethod) << std::endl;
        if (errorMethod)
            std::cout << "checkIfUniqueCharsUsingIntBitwise failing because of sizeof(long) < 5 (bytes)";

    }
    return 0;
}

/*
   Chapter 1 (Arrays and Strings) Problem 2
   TODO: add tests
*/


#include <iostream>
#include <algorithm>
#include <string>
#include <map>

// --returns true if iStr1 is permutation of iStr2
bool sol1(std::string iStr1, std::string iStr2) {
    if (iStr1.length() != iStr2.length()) return false;
    std::sort(iStr1.begin(), iStr1.end());
    std::sort(iStr2.begin(), iStr2.end());
    return (iStr1 == iStr2);
}


// --returns true if iStr1 is permutation of iStr2
bool sol2(std::string& iStr1, std::string& iStr2) {
    if (iStr1.size() != iStr2.size()) return false;
    std::map<char, int> iStr1Map;

    //add chars of iStr1 to a map
    for (auto const &a : iStr1) {
        ++iStr1Map[a];
    }
    // decrease the ocurrences of characters from iStr2 from iStr1Map
    for (auto const &a : iStr2) {
        if (iStr1Map.find(a) == iStr1Map.end())
            return false;
        else
            --iStr1Map[a];
    }
    // iterate through the map it should be 0 meaning we found exact letters counterparts from both iStr
    // this check could be done in the previous loop as well, checking: if (firstStr[a] < 0), which will not be true
    // if both str1 and str2 are the same
    for (auto it : iStr1Map) {
        if (it.second != 0)
            return 0;
    }
    // they are permutations
    return 1;
}

int main () {
    std::cout << "Please input both strings to check if they are permutations " << std::endl;
    std::string iStr1, iStr2;
    std::cin >> iStr1 >> iStr2;                  //TODO: could do getline to permit strings with whitespaces

    std::cout << "They are permutation of each other: " << sol1(iStr1, iStr2) << std::endl;
    std::cout << "They are permutation of each other: " << sol2(iStr1, iStr2) << std::endl;
    return 0;
}

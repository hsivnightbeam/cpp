/*
  Chapter 1 (Arrays and Strings) Problem 5
*/
#include <iostream>
#include <string>
#include <cstdlib>

// --method that checks if two str are 'offset' chars away from each other
// --output: true=>they are 'offset' away
bool oneEditAway(const std::string& iStr1, const std::string& iStr2, int offset) {
    bool editDetected = false;
    int index = 0;
    for (std::string::size_type i = 0; i < iStr2.size(); ++i) {
      if (iStr1[i] != iStr2[i - index]) {
            if (editDetected)
                return false;
            else
                editDetected = true;
                index = offset;
        }
    }
    return true;
}


// --method that checks if two str are more 0 or 1 edit(insert, remove or replace a char) away.
// --output: true=>they are just 0 or 1 edit away
bool sol1(const std::string& iStr1, const std::string& iStr2) {
    bool editDetected = false;
    if (abs((int)(iStr1.size() - iStr2.size())) > 1)
        return false;
    // if one of the string has 0 length this will be true
    if (iStr1.size() == 0 || iStr2.size() == 0)
        return true;
    else if ((iStr1.size() - iStr2.size()) == 0) {  //case they are the same size, only one char can differ
        return oneEditAway(iStr1, iStr2, 0);
    }
    else {                                          //if the size diff between both str is 1, we check there's exactly one diff at max
        if (iStr2.size() > iStr1.size())
            return oneEditAway(iStr2, iStr1, 1);
        return oneEditAway(iStr1, iStr2, 1);
    }
    return true;
}



int main () {
    std::string str1, str2;
    std::cout << "Please input both strings : " << std::endl;
    while (std::getline (std::cin,str1) &&
           std::getline (std::cin,str2)) {
        std::cout << "They are 0 or 1 edit away sol1: " <<  sol1(str1, str2) << std::endl;
        std::cout << "Please input both strings : " << std::endl;
    }
    return 0;
}

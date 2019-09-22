/*
  Chapter 1 (Arrays and Strings) Problem 6
*/
#include <iostream>
#include <string>

// --method that returns either the compressed string, or the original string if the size is equal or lower than the compressed
std::string sol1(const std::string& str) {
    if (str.size() < 3) return str;  //there's no way a 2 char str or smaller would be compressed (e.g. aa-> a2, or ab->a1b1).
                                     // With 3 it's possible (e.g. aaa->a3)
    std::string comprStr;
    char previousChar = str[0];
    int count  = 1;
    for (std::string::const_iterator it = (str.begin() + 1); it != str.end() && (comprStr.size() < str.size()); ++it) {
        if (*it != previousChar) {                                //the previous char is different than the current one, thus we append it to the comprStr
            comprStr.push_back(previousChar);
            comprStr += std::to_string(count);                    //could use append method
            previousChar = *it;
            count = 1;
        }
        else {                                                   //the previous char is equal than the current one, thus we increase the count
            count++;
        }
    }
    comprStr.push_back(previousChar);
    comprStr += std::to_string(count);
    return (comprStr.size() < str.size() ? comprStr : str);
}

int main () {
    std::string str;
    std::cout << "Please input the string to be compressed" << std::endl;
    while(std::cin >> str) {
        if (sol1(str) == str)
            std::cout << "Could not compress string " << std::endl;
        else
            std::cout << "Compressed str" << sol1(str) << std::endl;
        std::cout << "Please input the string to be compressed" << std::endl;
    }

    return 0;
}

/*
  Chapter 10 (Sorting and Searching) Problem 1
*/

#include <vector>
#include <iostream>

void merge (std::vector<int> &v1, std::vector<int> &v2) {
    //TODO: all these should be std::vector<int>::size_type...but then it cannot be negative and how would you detect end for looping?
    int ptr1 = v1.size()-1;
    int totalSize = v1.size()+v2.size();
    v1.resize(totalSize);
    int ptr2 = v2.size()-1;
    int ptr3 = totalSize-1;
    while (ptr1 >= 0 && ptr2 >= 0) {
        if (v1[ptr1] > v2[ptr2]) {
            v1[ptr3] = v1[ptr1];
            ptr1--;
        } else {
            v1[ptr3] = v2[ptr2];
            ptr2--;
        }
        ptr3--;
        for (auto i : v1) {
            std::cout << i << " " ;
        }
        std::cout << std::endl;
    }
    for (; 0 <= ptr2; --ptr2) {
        v1[ptr3--] = v2[ptr2];
        ptr3--;
    }
}

int main () {

    std::vector<int> v1 {-500, 5, 9, 16, 26, 34};
    std::vector<int> v2 {2, 7, 15, 16, 52};
    merge(v1, v2);
    for (auto i : v1) {
        std::cout << i << " " ;
    }
    std::cout << std::endl;

}


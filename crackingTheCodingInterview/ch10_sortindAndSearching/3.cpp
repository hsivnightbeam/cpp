/*
  Chapter 10 (Sorting and Searching) Problem 3
*/
#include <vector>
#include <iostream>

int checkVal(std::vector<int> &list, int targetElement, int index) {
    if (list[index] == targetElement)
        return index;
    return -1;
}

int findEl(std::vector<int> &list, int targetElement, int begIndex, int endIndex) {
    // base case...
    if (begIndex == endIndex)
        return checkVal(list, targetElement, begIndex);

    //another base case with two elements//actually if you just learn to implement binarysearch then this stupid thing would not be necessary: TODO....
    if (begIndex + 1 == endIndex)
        if (checkVal(list, targetElement, begIndex) != -1)
            return checkVal(list, targetElement, begIndex);
        else
            return checkVal(list, targetElement, endIndex);

    int midIndex = (begIndex + endIndex) / 2;

    int endElement = list[endIndex];
    int begElement = list[begIndex];
    int midElement = list[midIndex];

    if (targetElement >= midElement) {
        if (targetElement <= endElement ||     // xxxxxx 5    10                                          (target 9)
            endElement <= midElement)          // xxxxxx 5    2 ---> we will still find in this half      (target 9)
            return findEl(list, targetElement, midIndex, endIndex);
        else
            return findEl(list, targetElement, begIndex, midIndex);
    } else {
        if (targetElement >= begElement ||       // 0...5
            begElement > midElement)           //  10 ..0...5 target (3)
            return findEl(list, targetElement, begIndex, midIndex);
        else
            //return findEl(list, targetElement, midIndex, endIndex); //is this required or can just return -1?
            return findEl(list, targetElement, midIndex, endIndex);
    }
}





int main () {
    std::vector<int> list {4,5,6,7,0,1,2};
    int number;
    while (std::cin >> number){
        std::cout << findEl(list, number, 0, list.size()-1) << std::endl;
    }


}

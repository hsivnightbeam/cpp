/*
  Chapter 2 (Linked lists) Problem 6
*/

#include <iostream>
#include <algorithm>

struct Node {
    char data;
    Node* next;
    Node(char iData) : data{iData}, next{nullptr} { }
};

struct LinkedList {
    Node* head;
    Node* tail;
    std::size_t size;

    //Constructors
    LinkedList () : head{nullptr}, tail{nullptr}, size{0} { }
    explicit LinkedList (char iData) : head{new Node(iData)}, tail{head}, size{0} { }
    LinkedList (std::initializer_list<char> iDataList) : head {nullptr}, tail {nullptr}, size{0} {
        std::for_each(iDataList.begin(), iDataList.end(),
                      [this] (const int& i) { insert(i);});
    }

    //insert one element into the end (tail) of the linked list
    Node* insert (int iData) {
        if (head == nullptr) {   //if the list is empty
            head = tail = new Node(iData);
            size = 1;
            return tail;
        }
        Node* newEl = new Node(iData);
        tail->next = newEl;
        tail = newEl;
        ++size;
        return tail;
    }

    //output operator
    friend std::ostream& operator<<(std::ostream &os, const LinkedList& list);
};
//output operator for LinkedList class
std::ostream& operator<<(std::ostream &os, const LinkedList& list) {
    Node* it = list.head;
    while (it) {
        os << it->data << " ";
        it = it->next;
    }
    return os;
}

// --method to check if a linked list is a palindrome
bool isPalindrome(LinkedList &aL) {
    //we calculate the size of the list --> TODO should be a method of a Linked List ?
    int size = 0;
    Node* it = aL.head;
    while (it) {
        size++;
        it = it->next;
    }
    //bool isEven = static_cast<bool>(!(size % 2));
    bool isEven = !(size % 2) != 0;

    //Build the string of the first half
    std::string firstHalf;
    it = aL.head;
    for (int i = 0; i < size/2; ++i) {
        firstHalf.push_back(it->data);
        it = it->next;
    }
    //skip the middle character in uneven strings
    if (!isEven)
        it = it->next;
    int i = 0;
    //check for the second half of the str if its equal to the first half
    while (it) {
        if (it->data != firstHalf[firstHalf.size()-1-i])
            return false;
        it = it->next;
        ++i;
    }
    return true;
}

int main () {
    LinkedList aL{'a', 'b', 'c', 'b', 'a'};
    std::cout << "isPal " << isPalindrome(aL) << std::endl;
    return 0;
}
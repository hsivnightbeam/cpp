/*
  Chapter 2 (Linked lists) Problem 6
*/

#include <iostream>
struct Node {
    char p;
    Node* next;
    Node(char iP) : p{iP}, next{nullptr} { }
};

struct LinkedList {
    Node* head;
    Node* tail;
    LinkedList (char p) : head{new Node(p)}, tail{head} { }
    LinkedList () : head{nullptr}, tail{nullptr} { }
    Node* insert (char p) {
        Node* nextN = new Node(p);
        if (tail)
            tail->next = nextN;
        tail = nextN;
        if (!head)
            head = nextN;
        return tail;
    }

    void print() {
        Node* it = head;
        std::cout << "list: ";
        while (it) {
            std::cout << it->p << " ";
            it = it->next;
        }
        std::cout << std::endl;
    }
};

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
        firstHalf.push_back(it->p);
        it = it->next;
    }
    //skip the middle character in uneven strings
    if (!isEven)
        it = it->next;
    int i = 0;
    //check for the second half of the str if its equal to the first half
    while (it) {
        if (it->p != firstHalf[firstHalf.size()-1-i])
            return false;
        it = it->next;
        ++i;
    }
    return true;
}





int main () {
    LinkedList aL('a');
    aL.insert('b');
    aL.insert('c');
    aL.insert('b');
    aL.insert('a');
    std::cout << "isPal " << isPalindrome(aL) << std::endl;
    return 0;
}
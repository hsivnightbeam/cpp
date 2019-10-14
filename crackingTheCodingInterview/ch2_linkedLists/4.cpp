/*
  Chapter 2 (Linked lists) Problem 4
*/

#include <iostream>
#include <algorithm>

struct Node {
    int data;
    Node* next;
    Node(int iData) : data{iData}, next{nullptr} { }
};

struct LinkedList {
    Node* head;
    Node* tail;
    std::size_t size;

    //Constructors
    LinkedList () : head{nullptr}, tail{nullptr}, size{0} { }
    explicit LinkedList (int iData) : head{new Node(iData)}, tail{head}, size{0} { }
    LinkedList (std::initializer_list<int> iDataList) : head {nullptr}, tail {nullptr}, size{0} {
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

// --method that finds first portion of elements >= x, and returns it in Nodes [begPor, endPor]
void findFirstPortionGreaterThanPartionElem(LinkedList &aList, int partition, Node* &begPor, Node* &endPor, Node* &it) {
    //find first portion of elements >= partition
    bool foundPortion = false;
    while (!foundPortion && it) {
        if (it->data >= partition) {
            if (!begPor)
                begPor = endPor = it;
            else
                endPor = it;
        } else {
            if (begPor && endPor)   //if we already found at least one element in our portion of >= than partition
                foundPortion = true;
        }
        if (!foundPortion)
            it = it->next;
    }
}

// --method that swaps elements in the beginning of the portion with the element elSmallerToPart and updates the partition
void swapEl (Node* &begPor, Node* &endPor, Node* elSmallerToPart) {
    std::swap(begPor->data, elSmallerToPart->data);
    begPor = begPor->next;
    endPor = endPor->next;
}

// --method that does a partition on a linked list around a value x (values <x come before values >= x)
void sol (LinkedList &aList, int x) {
    Node* begPor = nullptr, *endPor = nullptr;
    Node* it = aList.head;

    //find first portion of elements >= x
    findFirstPortionGreaterThanPartionElem(aList, x, begPor, endPor, it);

    //now we just need to do repetead swaps until we reach the end
    while (it) {
        if (it->data < x) {
            swapEl(begPor, endPor, it);
        }
        it = it->next;
    }
}

int main () {
    LinkedList aList {3,2,8,4,9,1,5};
    std::cout << aList << std::endl;
    sol(aList, 5);
    std::cout << aList << std::endl;

    return 0;
}

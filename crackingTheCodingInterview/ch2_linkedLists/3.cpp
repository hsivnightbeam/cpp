/*
  Chapter 2 (Linked lists) Problem 3
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
// --method that deletes middle node (any node but the first and last node) of a singly linked list, given access to that node
void sol(Node* el) {
    Node* toDel = el->next;

    el->data = toDel->data;
    el->next = toDel->next;
    delete toDel;
}


int main () {
    LinkedList aList{3, 2, 4};
    Node* el = aList.insert(5);
    aList.insert(7);
    Node* el2 = aList.insert(25);
    aList.insert(33);

    std::cout << aList << " now deleting 5" << std::endl;
    sol(el);
    std::cout << aList << " now deleting 25" << std::endl;
    sol(el2);
    std::cout << aList << std::endl;

    return 0;
}


/*
  Chapter 2 (Linked lists) Problem 7
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
    //insert one node(that could point to other nodes) into the end (tail) of the linked list
    Node* insert (Node* el) {
        if (tail)
            tail->next = el;
        else {
            head = tail = el;
            return el;
        }
        while (tail->next)
            tail = tail->next;
        return el;
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

//--method to find the node (if it exists) in which 2 lists intersect
Node* findInt(LinkedList &aL1, LinkedList &aL2) {
    Node *it1 = aL1.head, *it2 = aL2.head;
    int sizeL1 = 0;
    while (it1) {
        ++sizeL1;
        it1 = it1->next;
    }
    int sizeL2 = 0;
    while (it2) {
        ++sizeL2;
        it2 = it2->next;
    }

    if (sizeL1 == sizeL2)
        return (aL1.head == aL2.head) ? aL1.head : nullptr;

    int dif = std::abs(sizeL1 - sizeL2);
    int elsL1 = sizeL1 - dif;
    it1 = aL1.head;
    for (int i = 0; i < elsL1; i++)
        it1 = it1->next;
    int elsL2 = sizeL2 - dif;
    it2 = aL2.head;
    for (int i = 0; i < elsL2; ++i)
        it2 = it2->next;
    return (it1->next == it2->next) ? it1->next : nullptr;
}


int main () {
    LinkedList aList1{'a','b','c','d'};
    auto el = aList1.insert('e');
    aList1.insert('f');

    LinkedList aList2{'g','i','j'};
    aList2.insert(el);

    std::cout << "List1 " << aList1 << std::endl;
    std::cout << "List2 " << aList2 << std::endl;

    auto common = findInt(aList1, aList2);
    std::cout << "element in common ";
    if (common)
        std::cout << common->data << std::endl;
    else
        std::cout << "none " << std::endl;


    return 0;
}
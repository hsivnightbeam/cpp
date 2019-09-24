/*
  Chapter 2 (Linked lists) Problem 3
*/

#include <iostream>

struct Node {
    int p;
    Node* next;
    Node(int iP) : p{iP}, next{nullptr} { }
};

struct LinkedList {
    Node* head;
    Node* tail;
    LinkedList (int p) : head{new Node(p)}, tail{head} { }
    Node* insert (int p) {
        Node* nextN = new Node(p);
        tail->next = nextN;
        tail = nextN;
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

// --method that deletes middle node (any node but the first and last node) of a singly linked list, given access to that node
void sol(Node* el) {
    Node* toDel = el->next;

    el->p = toDel->p;
    el->next = toDel->next;
    delete toDel;
}


int main () {
    LinkedList aList(3);
    aList.insert(2);
    aList.insert(4);
    Node* el = aList.insert(5);
    aList.insert(7);
    Node* el2 = aList.insert(25);
    aList.insert(33);

    aList.print();
    sol(el);
    aList.print();
    sol(el2);
    aList.print();

    return 0;
}


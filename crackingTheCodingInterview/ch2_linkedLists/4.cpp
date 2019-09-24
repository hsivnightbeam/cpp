/*
  Chapter 2 (Linked lists) Problem 4
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

// --method that finds first portion of elements >= x, and returns it in Nodes [begPor, endPor]
void findFirstPortionGreaterThanPartionElem(LinkedList &aList, int partition, Node* &begPor, Node* &endPor, Node* &it) {
    //find first portion of elements >= partition
    bool foundPortion = false;
    while (!foundPortion && it) {
        if (it->p >= partition) {
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
    std::swap(begPor->p, elSmallerToPart->p);
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
        if (it->p < x) {
            swapEl(begPor, endPor, it);
        }
        it = it->next;
    }
}

int main () {
    LinkedList aList {3};
    aList.insert (2);
    aList.insert (8);
    aList.insert(4);
    aList.insert(9);
    aList.insert(1);
    aList.insert(5);
    aList.print();
    sol(aList, 5);
    aList.print();

    return 0;
}

/*
  Chapter 2 (Linked lists) Problem 5
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
    LinkedList () : head{nullptr}, tail{nullptr} { }
    Node* insert (int p) {
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

// --method that sums 2 lists represented by op1 and op2, and returns a linkedList
LinkedList* solution(LinkedList &op1, LinkedList &op2) {    //TODO: implement return as with move constructor
    int carry = 0;
    Node* op1It = op1.head, *op2It = op2.head;
    LinkedList *result = new LinkedList;
    while (op1It && op2It) {
        result->insert((op1It->p + op2It->p + carry) % 10);
        carry = (op1It->p + op2It->p + carry) / 10;
        op1It = op1It->next;
        op2It = op2It->next;
    }
    if (op2It)
        std::swap(op1It, op2It);
    while (op1It) {
        result->insert((op1It->p + carry) % 10);
        carry = (op1It->p + carry) / 10;
    }
    if (carry)
        result->insert(carry);
    return result;
}



int main () {
    //7 1 6
    //5 9 2
    LinkedList p1 {7};
    p1.insert(1);
    p1.insert(6);

    LinkedList p2{5};
    p2.insert(9);
    p2.insert(2);

    LinkedList *result = solution(p1, p2);
    result->print();


    return 0;
}
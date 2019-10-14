/*
  Chapter 2 (Linked lists) Problem 5
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

// --method that sums 2 lists represented by op1 and op2, and returns a linkedList
LinkedList* solution(LinkedList &op1, LinkedList &op2) {
    int carry = 0;
    Node* op1It = op1.head, *op2It = op2.head;
    auto *result = new LinkedList;
    while (op1It && op2It) {
        result->insert((op1It->data + op2It->data + carry) % 10);
        carry = (op1It->data + op2It->data + carry) / 10;
        op1It = op1It->next;
        op2It = op2It->next;
    }
    if (op2It)
        std::swap(op1It, op2It);
    while (op1It) {
        result->insert((op1It->data + carry) % 10);
        carry = (op1It->data + carry) / 10;
    }
    if (carry)
        result->insert(carry);
    return result;
}



int main () {
    //7 1 6
    //5 9 2
    LinkedList p1 {7, 1, 6};
    LinkedList p2 {5, 9, 2};

    LinkedList *result = solution(p1, p2);
    std::cout << *result << std::endl;

    return 0;
}
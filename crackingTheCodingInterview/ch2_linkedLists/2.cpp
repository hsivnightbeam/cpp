/*
  Chapter 2 (Linked lists) Problem 2
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


// --method that finds the 'kth' to last element of a singly linked list
Node* sol1(LinkedList& list, int k) {
    Node *frontRunner = list.head, *backRunner = list.head;
    // advance k elements for frontRunner
    for (int i =0; i < k; i++) {
        if (!frontRunner->next) return nullptr;
        frontRunner = frontRunner->next;
    }
    // iterate until frontRunner hits the end, backRunner will be at the kth element
    while (frontRunner->next) {
        frontRunner = frontRunner->next;
        backRunner = backRunner->next;
    }
    return backRunner;
}

// --helper function for sol2
Node* kthToLastElementRecursiveHelper(Node* node, int k, int &element) {
    Node* nd = nullptr;
    if (node->next == nullptr) {
        element = 0;
    } else {
        nd = kthToLastElementRecursiveHelper(node->next, k, element);
        element++;
    }
    if (element == k)
        return node;
    return  nd;
}

// --method that finds the 'kth' to last element of a singly linked list in a recursive way
Node* sol2 (LinkedList& list, int k) {
    int element = 0;
    Node *head = list.head;
    return kthToLastElementRecursiveHelper(head, k, element);
}


int main () {
    LinkedList aList{1, 2, 4, 6, 8, 10, 12, 14, 16};
    std::cout << "list: " << aList << std::endl;
    
    int k;
    while (std::cout << "Please input kth to find: " && std::cin >> k) {
        auto res1 = sol1(aList, k);
        if (res1)
            std::cout << "kth to last is " << res1->data << std::endl;
        else
            std::cout << "kth to last doesn't exist (list too small)" << std::endl;

        auto resRecursiveSolution = sol2(aList, k);
        if (resRecursiveSolution)
            std::cout << "kth to last is " << resRecursiveSolution->data << std::endl;
        else
            std::cout << "kth to last can't be found with recursive solution (list too small)" << std::endl;
    }
    return 0;
}


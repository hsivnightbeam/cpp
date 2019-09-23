/*
  Chapter 2 (Linked lists) Problem 2
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
        while (it) {
            std::cout << it->p << " ";
            it = it->next;
        }
        std::cout << std::endl;
    }
};


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
    LinkedList aList(1);
    for (int i = 0; i < 8; ++i) {
        aList.insert(i+2);
    }

    std::cout << "list: ";
    aList.print();
    int k;
    while (std::cout << "Please input kth to find: " && std::cin >> k) {
        auto res1 = sol1(aList, k);
        if (res1)
            std::cout << "kth to last is " << res1->p << std::endl;
        else
            std::cout << "kth to last doesn't exist (list too small)" << std::endl;

        auto resRecursiveSolution = sol2(aList, k);
        if (resRecursiveSolution)
            std::cout << "kth to last is " << resRecursiveSolution->p << std::endl;
        else
            std::cout << "kth to last can't be found with recursive solution (list too small)" << std::endl;
    }
    return 0;
}


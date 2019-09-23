/*
  Chapter 2 (Linked lists) Problem 1
*/

#include <iostream>
#include <unordered_set>

struct Node {
    int p;                          //TODO: make int a template...needed for exercise 26 (also in the LinkedList since it uses an insert method)
    Node* next;
    Node(int iP) : p{iP}, next{nullptr} { }
};

struct LinkedList {
    Node* head;
    Node* tail;
    LinkedList (int p) : head{new Node(p)}, tail{head} { }   //TODO: implement initializer list.....
    Node* insert (int p) {                                   //do they just save size, required in 27 and somehwere else too..?
        Node* nextN = new Node(p);
        tail->next = nextN;
        tail = nextN;
        return tail;
    }

    // implement return as with move constructor as required for exercise 25.cpp

    void print() {          //probably implement this as an operator....
        Node* it = head;
        while (it) {
            std::cout << it->p << " ";
            it = it->next;
        }
        std::cout << std::endl;
    }
};

// --method that deletes duplicates from an unsorted linked list using external data structure
void sol1 (LinkedList aList) {
    Node* it = aList.head;
    std::unordered_set<int> records;
    records.insert(it->p);
    while (it->next) {
        if (records.find(it->next->p) != records.end()) {     //it already exists
            Node* duplicate = it->next;
            it->next = it->next->next;
            delete duplicate;
        } else {                                              //it's not a duplicate
            records.insert(it->next->p);
            it = it->next;
        }
    }
}

// --method that deletes duplicates from an unsorted linked list without using additional data structure
void sol2 (LinkedList n) {
    Node* current = n.head;
    while (current) {
        Node* runner = current;
        while (runner->next) {
            if (current->p == runner->next->p) {
                Node* toDelete = runner->next;
                runner->next = runner->next->next;
                delete toDelete;
            }
            else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}



int main () {
    LinkedList aList{2};
    aList.insert(3);
    aList.insert(2);
    aList.insert(4);
    aList.insert(5);
    aList.insert(3);
    aList.insert(3);
    std::cout << "list: ";
    aList.print();
    sol2(aList);
    std::cout << "list with no duplicates: ";
    aList.print();


    return 0;
}

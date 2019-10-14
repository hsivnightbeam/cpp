/*
  Chapter 2 (Linked lists) Problem 1
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>

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

// --method that deletes duplicates from an unsorted linked list using external data structure
void sol1 (LinkedList aList) {
    Node* it = aList.head;
    std::unordered_set<int> records;
    records.insert(it->data);
    while (it->next) {
        if (records.find(it->next->data) != records.end()) {     //it already exists
            Node* duplicate = it->next;
            it->next = it->next->next;
            delete duplicate;
        } else {                                                  //it's not a duplicate
            records.insert(it->next->data);
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
            if (current->data == runner->next->data) {
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
    LinkedList aList{2, 3, 2, 4, 5, 3, 3};
    std::cout << "list: " << aList << std::endl;
    sol2(aList);
    std::cout << "list with no duplicates: " << aList << std::endl;

    return 0;
}

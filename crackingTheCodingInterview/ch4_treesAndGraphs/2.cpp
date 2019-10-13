/*
  Chapter 4 (trees and graphs) Problem 2
*/
#include <vector>
#include <iostream>

struct Node {
    int data;
    Node *left, *right;
    Node(int iD) : data{iD}, left{nullptr}, right{nullptr} { }

    void print () {
        if (left) left->print();
        std::cout << data << " ";
        if (right) right->print();
    }
};

void createMinBst (const std::vector<int> &data, int first, int last, Node* &head)  {
    head = new Node {data[(first+last)/ 2]};
    if (first != last) {
        if (last - first > 1) //todo: i wonder is there a way of simplifying to avoid this....i don't think so but compare a bit the binary search algo with this when implementing to understand them well
            createMinBst(data, first, (first+last)/2-1, head->left);
        createMinBst(data, (first+last)/2+1, last, head->right);
    }
}



int main () {
    std::vector<int> data {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int first = 0, last = data.size()-1;
    Node* head = nullptr;

    createMinBst(data, first, last, head);
    head->print();


    return 0;
}
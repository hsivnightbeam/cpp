/*
  Chapter 4 (trees and graphs) Problem 4
*/

#include <iostream>
#include <algorithm>

// Struct Node for a tree node
struct Node {
    int data;
    Node *left, *right;
    explicit Node(int iData) : data{iData}, left{nullptr}, right{nullptr} { }
    //output operator
    friend std::ostream& operator<<(std::ostream &os, const Node& node);
};

//output operator for Node class
std::ostream& operator<<(std::ostream &os, const Node& node) {
    if (node.left) os << *node.left;
    os << node.data << " ";
    if (node.right) os << *node.right;
    return os;
}

// --method that creates a minimal tree from an sorted (increasing order) array iData, from index iFirstIdx, to iLastIdx
// --output in head
void createMinBst (const std::vector<int> &data, int first, int last, Node* &head)  {
    head = new Node {data[(first+last)/ 2]};
    if (first != last) {
        if (last - first > 1) //todo: i wonder is there a way of simplifying to avoid this....i don't think so but compare a bit the binary search algo with this when implementing to understand them well
            createMinBst(data, first, (first+last)/2-1, head->left);
        createMinBst(data, (first+last)/2+1, last, head->right);
    }
}
//TODO not sure height is working fine:
// for example below it gives equilibrium for both trees which seems wrong
int height (Node *head, bool &equilibrium) {
    int heightL=0, heightR=0;
    if (head->left)
        heightL= height(head->left, equilibrium);
    if (head->right)
        heightR= height(head->right, equilibrium);
    equilibrium = equilibrium && (std::abs(heightL-heightR) <= 1);
    return 1 + std::max(heightL, heightR);
}

int main () {
    //TODO: need to create something to create trees that are not balanced etc....
    std::vector<int> data {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int first = 0, last = data.size()-1;
    Node* head = nullptr;

    createMinBst(data, first, last, head);

    bool balanced = true;
    std::cout << "height of tree " <<  height(head, balanced) << " is it balanced? " << balanced << std::endl;

    createMinBst(data, first, last, head->right->left);
    std::cout << "height of tree " <<  height(head, balanced) << " is it balanced? " << balanced << std::endl;



    return 0;
}

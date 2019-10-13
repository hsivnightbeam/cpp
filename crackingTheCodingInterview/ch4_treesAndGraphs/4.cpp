/*
  Chapter 4 (trees and graphs) Problem 4
*/

#include <algorithm>

struct Node {
    int data;
    Node *left, *right;
    Node(int iD) : data{iD}, left{nullptr}, right{nullptr} { }
};



int height (Node *head, bool &equilibrium) {
    int heightL=0, heightR=0;
    if (head->left)
        heightL= height(head->left, equilibrium);
    if (head->right)
        heightR= height(head->right, equilibrium);
    equilibrium = (std::abs(heightL-heightR) <= 1);
    return 1 + std::max(heightL, heightR);
}

int main () {
    //TODO: need to create something to create trees that are not balanced etc....

    return 0;
}

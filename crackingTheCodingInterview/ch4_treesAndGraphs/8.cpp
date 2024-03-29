/*
  Chapter 4 (trees and graphs) Problem 8
*/
#include<iostream>
using namespace std;

// Struct Node for a tree Node
struct Node {
    int data;
    Node *left, *right;
    Node() : data {0}, left{nullptr}, right {nullptr} { }
    explicit Node(int iData) : data{iData}, left{nullptr}, right{nullptr} { }
    //output operator
    friend std::ostream& operator<<(std::ostream &os, const Node& Node);
};
//output operator for Node class
std::ostream& operator<<(std::ostream &os, const Node& Node) {
    if (Node.left) os << *Node.left;
    os << Node.data << " ";
    if (Node.right) os << *Node.right;
    return os;
}

void createMinimalBst(Node* &root, int arr[], int start, int end){
    if(start>end)
        return;
    if(root==NULL){
        Node *ptr = new Node;
        int ind = start + (end-start)/2;
        ptr->data = arr[ind];
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
        createMinimalBst(root->left, arr, start, ind-1);
        createMinimalBst(root->right, arr, ind+1, end);
    }
}

//root1 is decendent of root
bool isDecendent(Node *root, Node *root1){
    if(root == NULL)
        return false;
    if(root == root1)
        return true;
    return isDecendent(root->left, root1) || isDecendent(root->right, root1);
}

// --method to find the first common acestor between 2 Nodes(iNode1, iNode2) in a binary tree (root)
Node* commonAncestor(Node *root, Node *iNode1, Node *iNode2){
    if(root==NULL)
        return NULL;
    if(root == iNode1 || root == iNode2)
        return root;
    bool root1_on_left = isDecendent(root->left, iNode1);
    bool root2_on_left = isDecendent(root->left, iNode2);
    if(root1_on_left && root2_on_left)
        return commonAncestor(root->left, iNode1, iNode2);
    else if(root1_on_left || root2_on_left)
        return root;
    else
        return commonAncestor(root->right, iNode1, iNode2);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* root;
    root = NULL;
    createMinimalBst(root, arr, 0, 8);
    Node *ancestor = commonAncestor(root, root->left->left, root->left->right->right);
    cout<<ancestor->data;
}

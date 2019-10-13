/*
  Chapter 4 (trees and graphs) Problem 5
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

// --function that checks if a binary tree is binary search tree
bool checkIfBST(Node* head) {
    bool isBST = true;
    if (head->left) {
        if (head->data >= head->left->data)
            isBST = checkIfBST(head->left);
        else
            return false;
    }
    if (isBST && head->right) {
        if (head->data <= head->right->data)
            isBST = checkIfBST(head->right);
        else
            return false;
    }
    return isBST;
}



int main () {
    std::vector<int> data{0, 1, 2, 3, 4, 5, 6, 7, 8};
    int first = 0, last = data.size()-1;
    Node* head = nullptr;
    createMinBst(data, first, last, head);

    std::cout << checkIfBST(head) << std::endl;


    return 0;
}
/*#include<iostream>
#include<climits>
using namespace std;

struct node{
    int data;
    node *right, *left;
};

void createMinimalBst(node* &root, int arr[], int start, int end){
    if(start>end)
        return;
    if(root==NULL){
        node *ptr = new node;
        int ind = start + (end-start)/2;
        ptr->data = arr[ind];
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
        createMinimalBst(root->left, arr, start, ind-1);
        createMinimalBst(root->right, arr, ind+1, end);
    }
}

bool isBst(node* root, int lower, int upper){
    if(root==NULL){
        return true;
    }
    if(root->data<=upper && root->data>=lower){
        return (isBst(root->left, lower, root->data) && isBst(root->right, root->data+1, upper));
    }
    else
        return false;
}

int main(){
    int arr[] = {1, 2, 2, 4, 5, 6, 7, 8, 9};    //Not a BST
    int arr[] = {2, 2, 3, 4, 5, 6, 7, 8, 9};    //is BST
    node* root;
    root = NULL;
    createMinimalBst(root, arr, 0, 8);
    cout<<isBst(root, INT_MIN, INT_MAX);
}
*/
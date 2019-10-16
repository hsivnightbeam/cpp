/*
  Chapter 4 (trees and graphs) Problem 6
*/
#include<iostream>
#include<stack>
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
/*
Node* inOrderSuccessorWithParent(Node* root, Node* ptr){
    if(ptr->right){
        Node *p = ptr;
        while(p->left){
            p = p->left;
        }
        return p;
    }
    else{
        if(ptr==ptr->parent->left){
            return ptr->parent;
        }
        else{
            while(ptr!=ptr->parent->left){
                ptr = ptr->parent;
            }
            return ptr->parent;
        }
    }
}
*/

// --method to find the "next" Node of a given Node in a binary search tree
Node* inOrderSuccessor(Node* root, int k){
    stack<Node*> S;
    Node *ptr = root;
    bool searched = false;
    while(true){
        while(ptr){
            S.push(ptr);
            ptr = ptr->left;
        }
        if(S.empty())
            break;
        ptr = S.top();
        S.pop();
        //cout<<ptr->data<<" ";
        if(searched)
            return ptr;
        if(ptr->data==k){
            searched = true;
        }
        ptr = ptr->right;
    }
    return false;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node* root;
    root = NULL;
    createMinimalBst(root, arr, 0, 8);
    Node* searchedNode = inOrderSuccessor(root, 4);
    cout<<searchedNode->data<<'\n';
}

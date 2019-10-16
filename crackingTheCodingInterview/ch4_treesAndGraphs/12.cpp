/*
  Chapter 4 (trees and graphs) Problem 12
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

// --method that print paths (from go from parent Nodes to child Nodes) of a given sum
void printIfSum(int* arr, int sum, int len){
    for(int i=0; i<len; i++){
        int s=0;
        for(int j=i; j<len; j++){
            s += arr[j];
            if(s == sum){
                for(int k=i; k<=j; k++)
                    cout<<arr[k]<<" ";
                cout<<'\n';
            }
        }
    }
}

void print(Node *root, int sum, int *path, int level){
    if(root==NULL){
        return;
    }
    path[level] = root->data;
    int s = 0;
    for(int i=level; i>=0; i--){
        s += path[i];
        if(s==sum){
            for(int j=level; j>=i; j--)
                cout<<path[j]<<" ";
            cout<<'\n';
        }
    }
    if(root->left)
        print(root->left, sum, path, level+1);
    if(root->right)
        print(root->right, sum, path, level+1);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *root;
    root = NULL;
    createMinimalBst(root, arr, 0, 8);
    int path[100];
    print(root, 7, path, 0);
}

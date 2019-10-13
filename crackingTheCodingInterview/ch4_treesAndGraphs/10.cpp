/*
  Chapter 4 (trees and graphs) Problem 10
*/
#include<iostream>
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

bool isIdentical(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL)
        return true;
    if(root1 == NULL || root2 == NULL)
        return false;
    if(root1->data == root2->data && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right))
        return true;
    return false;
}

// --method to check if a tree (tree2) is a subtree of another tree (tree1)
bool isSubTree(node* tree1, node* tree2){
    if(tree1 == NULL && tree2 == NULL)
        return true;
    if(tree1 == NULL || tree2 == NULL)
        return false;
    return isIdentical(tree1, tree2) || isSubTree(tree1->left, tree2) || isSubTree(tree1->right, tree2);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};    // Bigger Tree
    int arr1[] = {1, 2, 3, 4};                  // Subtree
    node *root, *subRoot;
    root = subRoot = NULL;
    createMinimalBst(root, arr, 0, 8);
    createMinimalBst(subRoot, arr1, 0, 3);
    //cout<<isIdentical(root->left->left->left, subRoot->left);
    cout<<isSubTree(root, subRoot);
    return 0;
}

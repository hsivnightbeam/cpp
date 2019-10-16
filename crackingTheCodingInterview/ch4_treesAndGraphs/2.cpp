/*
  Chapter 4 (trees and graphs) Problem 2
*/
#include <vector>
#include <iostream>

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
void createMinBst (const std::vector<int> &iVector, int iFirstIdx, int iLastIdx, Node* &head)  {
    head = new Node {iVector[(iFirstIdx + iLastIdx) / 2]};
    if (iFirstIdx != iLastIdx) {
        if (iLastIdx - iFirstIdx > 1) //todo: i wonder is there a way of simplifying to avoid this....i don't think so
                                      // but compare a bit the binary search algo with this when implementing to understand them well
            createMinBst(iVector, iFirstIdx, (iFirstIdx + iLastIdx) / 2 - 1, head->left);
        createMinBst(iVector, (iFirstIdx + iLastIdx) / 2 + 1, iLastIdx, head->right);
    }
}



int main () {
    std::vector<int> data {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int first = 0, last = data.size()-1;
    Node* head = nullptr;

    createMinBst(data, first, last, head);
    std::cout << *head << std::endl;

    return 0;
}

/*
 *
struct node{
    int data;
    node *right, *left;
};

void createBst(node* &root, int arr[], int start, int end){
    if(start>end)
        return;
    if(root==NULL){
        node *ptr = new node;
        int ind = start + (end-start)/2;
        ptr->data = arr[ind];
        ptr->left = NULL;
        ptr->right = NULL;
        root = ptr;
        createBst(root->left, arr, start, ind-1);
        createBst(root->right, arr, ind+1, end);
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    node* root;
    root = NULL;
    createBst(root, arr, 0, 8);
    cout<<root->left->data<<" "<<root->data<<" "<<root->right->data<<'\n';
}

 */
/*
  Chapter 4 (trees and graphs) Problem 3
*/

#include <vector>
#include <list>
#include <queue>
#include <iostream>

struct Node {
    int data;
    Node *left, *right;
    Node (int iD) : data {iD}, left{nullptr}, right{nullptr} { }
    void print () {
        if (left) left->print();
        std::cout << data << " ";
        if (right) right->print();
    }
};



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


// --method that returns a vector of linked list of all the nodes at each depth
std::vector<std::list<Node*>> createListOfDepths (Node *head) {
    std::queue<Node*> q;
    q.push(head);
    int nodesCurrentLevel=1; int nodesNextLevel=0;
    std::vector<std::list<Node*>> result;
    std::list<Node*> currentDepthList;
    while (!q.empty()) {
        currentDepthList.push_back(q.front());
        if (q.front()->right) {
            ++nodesNextLevel;
            q.push(q.front()->right);
        }
        if (q.front()->left) {
            ++nodesNextLevel;
            q.push(q.front()->left);
        }
        q.pop();
        --nodesCurrentLevel;
        if (!nodesCurrentLevel) {
            result.push_back(currentDepthList);
            std::swap(nodesCurrentLevel, nodesNextLevel);
            currentDepthList.clear();
        }

    }
    return result;
}




int main () {
    std::vector<int> data {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int first = 0, last = data.size()-1;
    Node* head = nullptr;

    createMinBst(data, first, last, head);

    std::vector<std::list<Node*>> result = createListOfDepths(head);
    for (const auto &i : result) {
        for (const auto &j : i)
            std::cout << j->data << " ";
        std::cout << std::endl;
    }

}

/*
 * #include<iostream>
#include<vector>
#include<list>
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

void findLevelLinkedLists(vector<list<node*> > &res, node* root){
    list<node*> li;
    if (root != NULL)
        li.push_back(root);
    res.push_back(li);
    int depth = 0;
    while(!res[depth].empty()){
        list<node*> l;
        list<node*>::iterator iter;
        for(iter = res[depth].begin(); iter!=res[depth].end(); iter++ ){
            node *ptr = *iter;
            if(ptr->left)
                l.push_back(ptr->left);
            if(ptr->right)
                l.push_back(ptr->right);
        }
        res.push_back(l);
        depth++;
    }
}

void printLevelLinkedLists(vector<list<node*> > res){
    vector<list<node*> >::iterator iter;
    for(iter = res.begin(); iter!= res.end(); iter++){
        list<node*> li = *iter;
        list<node*>::iterator it;
        for(it = li.begin(); it!=li.end(); it++){
            node* ptr = *it;
            cout<<ptr->data<<" ";
        }
        cout<<'\n';
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    node* root;
    root = NULL;
    createMinimalBst(root, arr, 0, 8);
    vector<list<node*> > res;
    findLevelLinkedLists(res, root);
    printLevelLinkedLists(res);
}
 */
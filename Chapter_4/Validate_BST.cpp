#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
using std::cout;
using std::endl;



struct TREE_NODE{
    
    int data;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
};


//function to check if a tree is BST
//the tree is traversed inOrder and each new node is compared with its previous node "on the go"
//without extra memory usage; every node needs to be bigger than the previous one
bool check_BST_in_order(struct TREE_NODE *ptr){
    
    //static variable will only allocated once, the first time
    //on each subsequent iteration prev will remember its previous value
    static int prev = -1;
    
    if(ptr==NULL)
        return true;
    
    if(!check_BST_in_order(ptr->left))
        return false;
    
    if(prev >= ptr->data){
        return false;
    }
    prev = ptr->data;
    
    if(!check_BST_in_order(ptr->right))
        return false;
    
    return true;
}


//this algorithm checks for all nodes if all the nodes one the right of the current node are bigger than the current node
//and all the nodes on the left of the current node are smaller.
bool check_BST_min_max(struct TREE_NODE *ptr, int *min, int *max){
    
    if(ptr==NULL)
        return true;
    
    if((max!=NULL && ptr->data > *max) || (min != NULL && ptr->data < *min))
        return false;
    
    if(!check_BST_min_max(ptr->left, min, &ptr->data) || !check_BST_min_max(ptr->right, &ptr->data, max))
        return false;
    
    return true;
}




int main() {
    
    //manually construct the tree
    struct TREE_NODE *newNode = new(struct TREE_NODE);
    newNode->data = 5;
    
    struct TREE_NODE *newNode2 = new(struct TREE_NODE);
    newNode2->data = 3;
    
    struct TREE_NODE *newNode3 = new(struct TREE_NODE);
    newNode3->data = 4;
    
    struct TREE_NODE *newNode4 = new(struct TREE_NODE);
    newNode4->data = 8;
    
    struct TREE_NODE *newNode5 = new(struct TREE_NODE);
    newNode5->data = 7;
    
    struct TREE_NODE *newNode6 = new(struct TREE_NODE);
    newNode6->data = 9;

    struct TREE_NODE *newNode7 = new(struct TREE_NODE);
    newNode7->data = 1;

    
    newNode->right = newNode4;
    newNode->left = newNode2;
    
    newNode2->left = NULL;
    newNode2->right = newNode3;
    
    newNode3->left = NULL;
    newNode3->right = NULL;
    
    newNode4->left = newNode5;
    newNode4->right = newNode6;
    
    newNode5->left = NULL;
    newNode5->right = NULL;
    
    newNode6->left = NULL;
    newNode6->right = newNode7;
    
    newNode7->left = NULL;
    newNode7->right = NULL;
    
    if(check_BST_in_order(newNode))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
    if(check_BST_min_max(newNode, NULL, NULL))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
    return 0;
}

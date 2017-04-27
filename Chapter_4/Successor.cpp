#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
using std::cout;
using std::endl;

struct TREE_NODE {
    
    int data;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
    struct TREE_NODE *parent;
};



struct TREE {
    
    struct TREE_NODE *root;
    
    TREE(){
        root=NULL;
    }
    
    void insertNode(int x){
        
        struct TREE_NODE *myNode = new(struct TREE_NODE);
        myNode->data = x;
        myNode->left = NULL;
        myNode->right = NULL;
        
        if(root==NULL){
            root = myNode;
            myNode->parent = NULL;
        }
        
        else {
            struct TREE_NODE *ptr = root;
            
            while(ptr!=NULL) {
                myNode->parent = ptr;
                if (myNode->data > ptr->data)
                    ptr = ptr->right;
                else
                    ptr = ptr->left;
            }
            
            if ((myNode->data) < (myNode->parent->data))
                myNode->parent->left = myNode;
            else
                myNode->parent->right = myNode;
        }
    }
    
    
    void printTreeInOrder(struct TREE_NODE *ptr){
        if(ptr!=NULL){
            printTreeInOrder(ptr->left);
            cout << ptr->data << endl;
            printTreeInOrder(ptr->right);
        }
    }
    
    
    
    struct TREE_NODE * findSuccessor(struct TREE_NODE *node){
        
        if(node == NULL)
            return NULL;

        struct TREE_NODE *ptr = node;
        
        //move to the right and then always to the left until find NULL
        if(ptr->right != NULL){
            ptr = ptr->right;
            while(ptr->left != NULL)
                ptr = ptr->left;
            return ptr;
        }
        
        //if no right child is found move up to the parent
        //if current node is the left child of its parent then its parent is the successor
        else if (ptr == ptr->parent->left){
            ptr = ptr->parent;
            return ptr;
        }
        
        //if current node is the right child of its parent then move up
        //until current node is the left child of its parent
        else if(ptr == ptr->parent->right){
            
            ptr = ptr->parent;
            
            if(ptr==root)
                return NULL;
            
            while(ptr == ptr->parent->right)
                ptr=ptr->parent;
            
            if(ptr == ptr->parent->left){
                ptr = ptr->parent;
                return ptr;
            }
            else
                return NULL;
        }
        else
            return NULL;
    }
};



int main() {
    
    TREE myTree;
    
    
    myTree.insertNode(15);
    myTree.insertNode(4);
    myTree.insertNode(5);
    myTree.insertNode(8);
    myTree.insertNode(10);
    myTree.insertNode(1);
    myTree.insertNode(3);
    myTree.insertNode(20);
    myTree.insertNode(2);
    myTree.insertNode(18);
    myTree.insertNode(19);
                      
    myTree.printTreeInOrder(myTree.root);
    
    
    TREE_NODE *successor;
    
    
    successor = myTree.findSuccessor(myTree.root->left->right);
    if(successor==NULL)
        cout << myTree.root->left->right->data << " does not have a successor" << endl;
    else
        cout << "successor of " << myTree.root->left->right->data << " is " << successor->data << endl;
    
    successor = myTree.findSuccessor(myTree.root->left->right->right);
    if(successor==NULL)
        cout << myTree.root->left->right->right->data << " does not have a successor" << endl;
    else
        cout << "successor of " << myTree.root->left->right->right->data << " is " << successor->data << endl;

    
    successor = myTree.findSuccessor(myTree.root->left);
    if(successor==NULL)
        cout << myTree.root->left->data << " does not have a successor" << endl;
    else
        cout << "successor of " << myTree.root->left->data << " is " << successor->data << endl;
    
    
    
    successor = myTree.findSuccessor(myTree.root->right);
    if(successor==NULL)
        cout << myTree.root->right->data << " does not have a successor" << endl;
    else
        cout << "successor of " << myTree.root->right->data << " is " << successor->data << endl;
    
    successor = myTree.findSuccessor(myTree.root);
    if(successor==NULL)
        cout << myTree.root->data << " does not have a successor" << endl;
    else
        cout << "successor of " << myTree.root->data << " is " << successor->data << endl;
    
    successor = myTree.findSuccessor(myTree.root->left->left);
    if(successor==NULL)
        cout << myTree.root->left->left->data << " does not have a successor" << endl;
    else
        cout << "successor of " << myTree.root->left->left->data << " is " << successor->data << endl;
    
    successor = myTree.findSuccessor(myTree.root->left->left->right);
    if(successor==NULL)
        cout << myTree.root->left->left->right->data << " does not have a successor" << endl;
    else
        cout << "successor of " << myTree.root->left->left->right->data << " is " << successor->data << endl;
    
    
    successor = myTree.findSuccessor(myTree.root->left->left->right->left);
    if(successor==NULL)
        cout << myTree.root->left->left->right->left->data << " does not have a successor" << endl;
    else
        cout << "successor of " << myTree.root->left->left->right->left->data << " is " << successor->data << endl;
    
    
    
    successor = myTree.findSuccessor(myTree.root->left->right->right->right);
    if(successor==NULL)
        cout << myTree.root->left->right->right->right->data << " does not have a successor" << endl;
    else
        cout << "successor of " << myTree.root->left->right->right->right->data << " is " << successor->data << endl;
    
    
    
    successor = myTree.findSuccessor(myTree.root->right->left);
    if(successor==NULL)
        cout << myTree.root->right->left->data << " does not have a successor" << endl;
    else
        cout << "successor of " << myTree.root->right->left->data << " is " << successor->data << endl;
    
    
    successor = myTree.findSuccessor(myTree.root->right->left->right);
    if(successor==NULL)
        cout << myTree.root->right->left->right->data << " does not have a successor" << endl;
    else
        cout << "successor of " << myTree.root->right->left->right->data << " is " << successor->data << endl;
    
    return 0;
}

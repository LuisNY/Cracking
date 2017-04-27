#include <stdio.h>
#include <vector>
#include <iostream>
#define N 10
using namespace std;
using std::vector;


struct TREE_NODE{
    
    int data;
    struct TREE_NODE *left;
    struct TREE_NODE *right;
};


//this algorithm creates a new node (root) for the subsection that it is passed
struct TREE_NODE * createMinimalBST(vector<int> myVect, int start, int end){
    
    if(end<start)
        return NULL;
    
    struct TREE_NODE *myNode = new(struct TREE_NODE);
    
    int mid = (end+start)/2;
    cout << start << " " << myVect[mid] << " " << end << endl;
    myNode->data = myVect[mid];
    myNode->left = createMinimalBST(myVect, start, mid-1);
    myNode->right = createMinimalBST(myVect, mid+1, end);
    
    return myNode;
}


void createBST(vector<int> myVect){
    createMinimalBST(myVect, 0, (int)myVect.size()-1);
    return;
}


int main() {
    
    vector<int> myVect(N-1);
    for(int i=0; i<N-1; i++)
        myVect[i] = i;
    
    createBST(myVect);
    
    return 0;
}


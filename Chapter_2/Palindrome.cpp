#include <iostream>

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <string>
#include <list>
#include <sstream>
#include <deque>
#include <stack>

using namespace std;
using std::unordered_set;
using std::string;
using std::list;
using std::stack;
using std::vector;
using std::make_pair;
using std::deque;

struct NODE {
    int data;
    struct NODE *next;
};


struct LIST {
    
    struct NODE *head=NULL;
    stack<int> myStack;
    struct NODE *helpList=NULL;
    
    void insert(int x){
        
        struct NODE *myNode = new(struct NODE);
        myNode->data = x;
        myNode->next = NULL;
        
        if (head==NULL){
            head = myNode;
        }
        else {
            struct NODE *ptr = head;
            while(ptr->next != NULL){
                ptr=ptr->next;
            }
            ptr->next = myNode;
        }
    }
    
    void printList(){
        
        struct NODE *ptr = head;
        while(ptr != NULL){
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
    
    
    
    //check if the list is palindrome using a stack, insert the first half of the list into a stack and
    //check if the elements in the second half of the list correspond to the element in the stack (in reverse)
    bool check_pal_with_stack(){
        
        int cont=0;
        int N=0;
        
        struct NODE *ptr = head;
        while(ptr!=NULL){
            N++;
            ptr=ptr->next;
        }
        
        ptr=head;

        while(cont <= N/2){
            myStack.push(ptr->data);
            ptr=ptr->next;
            cont++;
        }
        
        //if N is odd do not consider the middle element
        if (N%2!=0){
            myStack.pop();
        }
        else {
            int temp = myStack.top();
            myStack.pop();
            if(temp != myStack.top())
                return false;
            myStack.pop();
        }
        
        while(cont < N){
            if (myStack.top() != ptr->data)
                return false;
            myStack.pop();
            ptr=ptr->next;
            cont++;
        }
        return true;
    }
    
    
    //check if the list is palindrome by reversing the list and comparing the new list with the original one
    bool check_pal_reverse_compare(){
        
        reverse_list();
        
        struct NODE *ptr1 = head;
        struct NODE *ptr2 = helpList;
        
        while(ptr1!=NULL && ptr2!=NULL){
            
            if(ptr1->data != ptr2->data)
                return false;
            
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        
        return true;
    }
    
    //create new list in reverse order
    void reverse_list(){
        
        struct NODE *ptr = head;
        
        while(ptr!=NULL){
            
            struct NODE *new_node = new(struct NODE);
            
            new_node->data = ptr->data;
            new_node->next = helpList;
            helpList = new_node;
            
            ptr=ptr->next;
        }
    }
};




int main() {
    
    LIST myList;
    
    myList.insert(1);
    myList.insert(2);
    myList.insert(2);
    myList.insert(5);
    myList.insert(3);
    myList.insert(10);
    myList.insert(18);
    myList.insert(19);
    myList.insert(19);
    myList.insert(18);
    myList.insert(10);
    myList.insert(3);
    myList.insert(5);
    myList.insert(2);
    myList.insert(2);
    myList.insert(1);
    
    myList.printList();
    cout << endl;
    
    if(myList.check_pal_with_stack())
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    cout << endl;
    
    if(myList.check_pal_reverse_compare())
        cout << "yes" << endl;
    else
        cout << "no" << endl;
    
    
    return 0;
}

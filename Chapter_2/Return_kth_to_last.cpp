#include <stdio.h>
#include <iostream>

using namespace std;
using std::cout;
using std::endl;

struct NODE {
    int data;
    struct NODE *next;
};

class LIST {

public:    
    struct NODE *head;

LIST() {
        head = NULL;
    }
    
    void insert(int x){
        
        struct NODE *ptr = new (struct NODE);
        ptr->data = x;
        ptr->next = NULL;
        
        if(head == NULL){
            head = ptr;
        }
        
        else {
            struct NODE *ptr2 = head;
            while(ptr2->next != NULL){
                ptr2=ptr2->next;
            }
            ptr2->next = ptr;
        }
    }
    
    
    
    void printList(){
        struct NODE *ptr = head;
        
        while(ptr != NULL){
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
    
    //iterative solution with two pointers that are k nodes away from each other
    //when one hits the end the other will point to our node of interest
    void printKthToLastIterative(int k){
        
        if(head == NULL){
            cout << "no elements" << endl;
            return;
        }
        struct NODE * ptr = head;
        int i=0;
        while(ptr != NULL && i<=k){
            ptr=ptr->next;
            i++;
        }

        if(ptr==NULL){
            cout << "less than or equal to " << k << " elements in the list" << endl;
            return;
        }
        
        struct NODE *ptr2 = head;
        
        while (ptr!=NULL) {
            ptr=ptr->next;
            ptr2=ptr2->next;
        }
        
        cout << ptr2->data << endl;
    }
    
    
    //recursive solution that uses a reference to the counter i 
    struct NODE* printKthToLastRecursive(struct NODE *head, int k, int& i){
        
        if(head==NULL)
            return NULL;
        
        struct NODE * ptr = printKthToLastRecursive(head->next, k, i);
        
        i = i+1;
        
        if(i==k)
            return head;
        
        return ptr;
    }
};


int main(){
    
    LIST myList;
    
    int i=0;
    struct NODE* ptr = myList.printKthToLastRecursive(myList.head, 2, i);
    if(ptr==NULL)
        cout << "not possible" << endl;
    else {
        cout << ptr->data << endl;
    }
    
    myList.insert(1);
    myList.insert(3);
    myList.insert(2);
    myList.insert(4);
    myList.insert(5);
    
    //myList.printList();
    cout << endl;
    
    i=0;
    ptr = myList.printKthToLastRecursive(myList.head, 2, i);
    if(ptr==NULL)
        cout << "not possible" << endl;
    else {
        cout << ptr->data << endl;
    }

    i=0;
    ptr = myList.printKthToLastRecursive(myList.head, 6, i);
    if(ptr==NULL)
        cout << "not possible" << endl;
    else {
        cout << ptr->data << endl;
    }

    i=0;
    ptr = myList.printKthToLastRecursive(myList.head, 1, i);
    if(ptr==NULL)
        cout << "not possible" << endl;
    else {
        cout << ptr->data << endl;
    }

    i=0;
    ptr = myList.printKthToLastRecursive(myList.head, 0, i);
    if(ptr==NULL)
        cout << "not possible" << endl;
    else {
        cout << ptr->data << endl;
    }

    
    //cout << myList.printKthToLastRecursive(myList.head, 6, i)->data << endl;
    //cout << myList.printKthToLastRecursive(myList.head, 1, i)->data << endl;
    //cout << myList.printKthToLastRecursive(myList.head, 0, i)->data << endl;
    
    
    
    
    
    return 0;
}

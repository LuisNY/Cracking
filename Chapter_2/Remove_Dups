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

using namespace std;
using std::unordered_set;
using std::string;
using std::list;
using std::vector;
using std::make_pair;
using std::deque;

struct NODE {
    int data;
    struct NODE *next;
};

struct LIST {
    
    struct NODE *head;
    unordered_set<int> myHashTable;
    
    LIST() {
        head = NULL;
    }
    
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
    
    
    //use an hashtable, everytime you find a new value in the list check if it's already in the table,
    //if so delete it, otherwise insert this element into the hash table
    //run time is O(N) because you have to go trhough the whole list once, but uses extra buffer (hashtable)
    void remove_dups_with_buff(){
        
        struct NODE *ptr = head;
        struct NODE *ptr_prev = NULL;
        
        while(ptr != NULL){
            
            if(myHashTable.find(ptr->data) == myHashTable.end()){
                myHashTable.insert(ptr->data);
                ptr_prev = ptr;
            }
            else {
                ptr_prev->next = ptr->next;
            }
            ptr=ptr->next;
        }
    }
    
    
    //this algorithm works in place, no extra memory needed, but run time is O(N^2)
    void remove_dups_in_place(){
        
        struct NODE *ptr1 = head;
        
        while(ptr1 != NULL){
            
            struct NODE *ptr2 = ptr1;
            
            while(ptr2->next != NULL){
                
                if(ptr2->next->data == ptr1->data){
                    ptr2->next = ptr2->next->next;
                }
                else {
                    ptr2=ptr2->next;
                }
            }
            ptr1=ptr1->next;
        }
    }
    
};


int main() {
    
    LIST myList;
    
    myList.insert(1);
    myList.insert(5);
    myList.insert(1);
    myList.insert(5);
    myList.insert(3);
    myList.insert(6);
    myList.insert(1);
    
    myList.printList();
    
    myList.remove_dups_with_buff();
    //myList.remove_dups_in_place();
    
    cout << endl;
    myList.printList();
    
    return 0;
}

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

struct LISTS {
    
    struct NODE *list1;
    struct NODE *list2;
    struct NODE *sum;
    int temp;
    int carry;
    LISTS() {
        sum = NULL;
        carry = 0;
        temp = 0;
    }
    
    void insert1(int x){
        
        struct NODE *myNode = new(struct NODE);
        myNode->data = x;
        myNode->next = NULL;
        
        if (list1==NULL){
            list1 = myNode;
        }
        else {
            struct NODE *ptr = list1;
            while(ptr->next != NULL){
                ptr=ptr->next;
            }
            ptr->next = myNode;
        }
    }
    
    void insert2(int x){
        
        struct NODE *myNode = new(struct NODE);
        myNode->data = x;
        myNode->next = NULL;
        
        if (list2==NULL){
            list2 = myNode;
        }
        else {
            struct NODE *ptr = list2;
            while(ptr->next != NULL){
                ptr=ptr->next;
            }
            ptr->next = myNode;
        }
    }
    
    
    
    void sumLists(){
        
        struct NODE *ptr1 = list1;
        struct NODE *ptr2 = list2;
        
        while((ptr1!=NULL && ptr2!=NULL)){
            
            temp = carry + ptr1->data + ptr2->data;
            carry = temp/10;
            temp %= 10;
            
            struct NODE *new_node = new(struct NODE);
            new_node->data = temp;
            new_node->next = NULL;
            
            if(sum==NULL){
                sum = new_node;
            }
            else {
                struct NODE *ptr = sum;
                while(ptr->next!=NULL)
                    ptr = ptr->next;
                ptr->next = new_node;
            }
            
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        
        
        if(ptr1!=NULL){
            while(ptr1!=NULL){
                
                struct NODE *new_node = new(struct NODE);
                new_node->data = ptr1->data + carry;
                new_node->next = NULL;
                carry=0;
                
                if(sum==NULL){
                    sum = new_node;
                }
                else {
                    struct NODE *ptr = sum;
                    while(ptr->next!=NULL)
                        ptr = ptr->next;
                    ptr->next = new_node;
                }
                
                ptr1=ptr1->next;
            }
        }
        
        else if (ptr2!=NULL) {
            while(ptr2!=NULL){
                
                struct NODE *new_node = new(struct NODE);
                new_node->data = ptr2->data + carry;
                new_node->next = NULL;
                carry=0;
                
                if(sum==NULL){
                    sum = new_node;
                }
                else {
                    struct NODE *ptr = sum;
                    while(ptr->next!=NULL)
                        ptr = ptr->next;
                    ptr->next = new_node;
                }
                
                ptr2=ptr2->next;
            }
        }
        
        else if(carry!=0){
            struct NODE *new_node = new(struct NODE);
            new_node->data = carry;
            new_node->next = NULL;
            if(sum==NULL){
                sum = new_node;
            }
            else {
                struct NODE *ptr = sum;
                while(ptr->next!=NULL)
                    ptr = ptr->next;
                ptr->next = new_node;
            }
        }
    }
    
    void printList(struct NODE *list){
        struct NODE *ptr = list;
        while(ptr != NULL){
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
        cout << endl;

    }
    

    
    void printSum(){
        struct NODE *ptr = sum;
        while(ptr != NULL){
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
    }
    
};


int main() {
    
    LISTS myLists;
    
    myLists.insert1(1);
    myLists.insert1(7);
    myLists.insert1(3);
    myLists.insert1(1);
    myLists.insert1(9);
    myLists.insert1(1);
    myLists.insert2(0);
    myLists.insert2(1);
    myLists.insert2(2);
    myLists.insert2(0);
    myLists.insert2(1);
    myLists.insert2(2);

    
    myLists.printList(myLists.list1);
    myLists.printList(myLists.list2);
    
   
    myLists.sumLists();
    myLists.printSum();
    
    return 0;
}

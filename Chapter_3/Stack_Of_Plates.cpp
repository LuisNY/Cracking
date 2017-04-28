#include <stdio.h>
#include <vector>
#include <iostream>
#include <stack>
#include <math.h>

using namespace std;
using std::vector;
using std::cout;
using std::endl;
using std::stack;

//the stack is made of a vector of stacks
//pop() and push() will add/remove the last element of the last stack in the vector
class STACK {
    
    vector< stack<int> > myVect;
    int stackCapacity;
    
public:
    
    STACK(int capacity){
        stackCapacity = capacity;
    }
    
    void push(int x){
        if(myVect.size()==0){
            addNewStack(x);
        } else {
            stack<int> lastStack = myVect[myVect.size()-1];
            if(lastStack.size()>=stackCapacity){
                addNewStack(x);
            } else {
                myVect[myVect.size()-1].push(x);
            }
        }
    }

    void addNewStack(int x){
        stack<int> newStack;
        newStack.push(x);
        myVect.push_back(newStack);
    }
    
    void pop(){
        if(myVect.size()==0){
            cout<< "stack is empty" << endl;
        } else {
            cout << "popping value " << myVect[myVect.size()-1].top() << endl << endl;
            myVect[myVect.size()-1].pop();
            if(myVect[myVect.size()-1].size() == 0){
                myVect.pop_back();
            }
        }
    }
    
    void printStack(){
        if(myVect.size()>0){
            for(int i=0; i<myVect.size(); i++){
                cout << "stack " << i << "   size " << myVect[i].size() << endl;
            }
        } else {
            cout<< "stack is empty" << endl;
        }
        cout << endl;
    }
};



int main() {
    
    
    STACK myStack(5);
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    myStack.push(6);
    
    myStack.printStack();
    
    
    myStack.pop();
    myStack.printStack();
    
    myStack.push(7);
    myStack.push(8);
    myStack.push(9);
    myStack.push(10);
    myStack.push(11);
    myStack.push(12);
    
    myStack.printStack();
    
    myStack.pop();
    myStack.printStack();
    
    return 0;
}

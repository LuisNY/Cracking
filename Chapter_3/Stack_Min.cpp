/*
 implementation using pairs of values for each element of the vector

 */

#include <iostream>
#include <deque>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
using std::deque;
using std::queue;
using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::vector;




class myStack {
    
    vector< pair<int, int> > myVect;
    int min;
    
public:
    
    void push(int x) {
        
        pair <int, int> myPair;
        
        if (myVect.empty() || min > x){
            min = x;
        }
        
        myPair = make_pair(x, min);
        myVect.push_back(myPair);
    }
    
    void pop() {
        
        if (!myVect.empty()){
            myVect.pop_back();
        }
    }
    
    void minVal(){
        
        if (myVect.empty()){
            cout << "Stack is empty" << endl;
        }
        else {
            cout << myVect.back().second << endl;
        }
    }
    
};


int main(){
    
    myStack Stack;
    
    Stack.push(4);
    Stack.minVal();
    Stack.push(3);
    Stack.minVal();
    Stack.push(5);
    Stack.minVal();
    Stack.pop();
    Stack.minVal();
    Stack.pop();
    Stack.minVal();
    Stack.pop();
    Stack.minVal();
    Stack.pop();
    Stack.minVal();
    Stack.push(1);
    Stack.minVal();
    return 0;
}

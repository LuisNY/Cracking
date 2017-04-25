/*
 
 Implementation using 2 stacks
 
 */

#include <iostream>
#include <deque>
#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
using std::deque;
using std::queue;
using std::cout;
using std::endl;
using std::cin;
using std::ostream;
using std::vector;
using std::stack;






class myStack {
    
    stack<int> s1;
    stack<int> s2;
    
public:
    
    
    void push(int x){
        s1.push(x);
        
        if(s2.empty() || s2.top()>=x){
            s2.push(x);
        }
        
    }
    
    void pop(){
        
        if(!s1.empty()){
            if(s1.top() == s2.top())
                s2.pop();
            
            s1.pop();
        }
        
        else{
            
            cout << "s1 is empty" << endl;
        }
        
        
    }
    
    void minVal(){
        
        if(!s2.empty())
            cout << s2.top() << endl;
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


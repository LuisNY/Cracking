
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#define N 10 //max capacity for all 3 stacks

using namespace std;
using std::string;
using std::unordered_map;
using std::pair;
using std::vector;



//implement 3 stacks using one array
//the stacks have flexible length so that no space is wasted when one is full and the others are empty
//the three stacks are always ordered so that #1 come first then #2 and #3
class STACKS {
    
    vector<int> myVect;
    int start1, start2, start3;
    int size1, size2, size3;
    
public:
    STACKS() : myVect(N, 0) {
        start1=-1;
        start2=-1;
        start3=-1;
        size1=0;
        size2=0;
        size3=0;
    } //constructor
    
    void push(int numStack, int newElem){
        
        if(checkIfStacksFull())
            cout << "Stack is currently full." << endl;
        
        else {
            switch (numStack) {
                case 1:

                    if(size3>0){
                        for(int i=start3+size3-1; i>=start3; i--){
                            myVect[i+1] = myVect[i];
                        }
                        start3 = start3 + 1;
                    }
                    
                    if(size2>0){
                        for(int i=start2+size2-1; i>=start2; i--){
                            myVect[i+1] = myVect[i];
                        }
                        start2 = start2 + 1;
                    }
                    
                    start1 = 0;
                    myVect[start1+size1] = newElem;
                    size1 = size1+1;
                    
                    break;
                    
                case 2:
                    
                    if(size3>0){
                        for(int i=start3+size3-1; i>=start3; i--){
                            myVect[i+1] = myVect[i];
                        }
                        start3 = start3 + 1;
                    }
                    
                    start2 = start1+size1;
                    myVect[start2+size2] = newElem;
                    size2 = size2+1;
                    
                    break;
                    
                case 3:
                    
                    if(size2>0){
                        start3 = start2+size2;
                    }
                    else {
                        start3 = start1+size1;
                    }
                    
                    myVect[start3 + size3] = newElem;
                    size3 = size3+1;
                    
                    break;
                    
                default:
                    break;
            }
        }
        
        cout << "push" << endl;
        cout << "size1 " << size1 << "   start1 " << start1 << endl;
        cout << "size2 " << size2 << "   start2 " << start2 << endl;
        cout << "size3 " << size3 << "   start3 " << start3 << endl;
        cout << endl;
    }
    
    void pop(int numStack){
        
        switch (numStack) {
            case 1:
                if(size1>0){
                    if(size2>0){
                        for(int i=start2; i<start2+size2; i++)
                            myVect[i-1] = myVect[i];
                        start2 = start2-1;
                    }
                    if(size3>0){
                        for(int i=start3; i<start3+size3; i++)
                            myVect[i-1] = myVect[i];
                        start3 = start3-1;
                    }
                    
                    size1 = size1-1;
                }
                break;
                
            case 2:
                if(size2>0){
                    if(size3>0){
                        for(int i=start3; i<start3+size3; i++)
                            myVect[i-1] = myVect[i];
                        start3 = start3-1;
                    }
                    size2=size2-1;
                }
                break;
            
            case 3:
                if(size3>0){
                    size3 = size3-1;
                }
                break;
            
            default:
                break;
        }
        
        cout << "pop" << endl;
        cout << "size1 " << size1 << "   start1 " << start1 << endl;
        cout << "size2 " << size2 << "   start2 " << start2 << endl;
        cout << "size3 " << size3 << "   start3 " << start3 << endl;
        cout << endl;
    }
    
    bool checkIfStacksFull() {
        if(size1+size2+size3>=N)
            return true;
        return false;
    }
    
    void printVect(){
        
        for (int i=0; i<size1+size2+size3; i++)
            cout << myVect[i] << " ";
        cout << endl;
    }
};

int main() {
    
    STACKS myStacks;
    
    myStacks.push(1, 0);
    myStacks.push(1, 1);
    myStacks.push(1, 0);
    myStacks.push(2, 1);
    myStacks.push(3, 3);
    myStacks.push(1, 9);
    myStacks.push(2, 8);
    myStacks.push(1, 9);
    myStacks.push(3, 1);
    myStacks.push(3, 1);
    myStacks.push(3, 9);
    myStacks.printVect();
    myStacks.pop(2);
    myStacks.pop(1);
    myStacks.push(3, 9);
    myStacks.push(3, 0);
    myStacks.push(3, 2);
    
    myStacks.printVect();
    return 0;
}

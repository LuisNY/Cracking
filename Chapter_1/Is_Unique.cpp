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


void solve_using_hash_table(){
    
    unordered_set<char> mySet;
    string myString;
    cin >> myString;
    
    bool flag=true;
    
    //if the considered character is not in the hashtable yet, insert it into the table
    //if the considered character is found in the hashtable, return false
    for (int i=0; i<myString.size(); i++){
        
        if (mySet.find(myString[i]) == mySet.end())
            mySet.insert(myString[i]);
        else{
            flag=false;
            break;
        }
    }
    
    if(flag)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}


int main() {
    
    solve_using_hash_table();
    
    
    return 0;
}

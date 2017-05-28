#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using std::endl;
using std::cout;
using std::cin;

string compressString(string str){
    
    string newStr;
    int i=0;
    while(i<str.size()){
        
        int count=0;
        char temp=str[i];
        
        while(i<str.size() && temp==str[i]){
            count++;
            i++;
        }
        
        newStr += temp;
        newStr += std::to_string(count);
    }
    
    if(newStr.size() < str.size())
        return newStr;
    
    return str;
}

int main() {
       
    string comprStr;
    cin >> comprStr;
    cout << compressString(comprStr) << endl;
    
    return 0;
}

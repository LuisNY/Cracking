#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using std::endl;
using std::cout;
using std::cin;

bool checkStrings(string str1, string str2){
    
    if(abs((int)str1.size()-(int)str2.size())>1)
        return false;
    
    bool flag=true;
    
    string strMin = (str1.size() < str2.size()) ? str1 : str2;
    string strMax = (str1.size() > str2.size()) ? str1 : str2;
    
    
    int errors=0;
    int i=0;
    
    if(strMin.size()!=strMax.size()){

        int j=0;

        while(i<strMin.size()){
            
            if(strMin[i]!=strMax[j]){
                errors++;
                j++;
            }
            
            if(errors>1){
                flag=false;
                break;
            }
            j++;
            i++;
        }
    }
    else{
        while(i<strMin.size()){
            
            if(strMin[i]!=strMax[i]){
                errors++;
            }
            
            if(errors>1){
                flag=false;
                break;
            }
            i++;
        }
    }
    
    return flag;
}


int main() {
    
    string str1, str2;
    
    cin >> str1 >> str2;
    
    if(checkStrings(str1, str2))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    
    return 0;
}

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
using std::string;
using std::unordered_map;
using std::pair;


//first solution - check character counts; use unordered_map containers (hashtables)
void check_character_counts(string str1, string str2){
    
    //check if the strings have the same length
    if(str1.size() != str2.size()){
        cout << "no" << endl;
        return;
    }
    
    unordered_map<char, int> myMap1, myMap2;
    
    for (int i=0; i<str1.size(); i++){
        
        if(myMap1.find(str1[i]) == myMap1.end()) {
            pair<char, int> myPair;
            myPair = make_pair(str1[i], 1);
            myMap1.insert(myPair);
        } else {
            myMap1.at(str1[i])++;
        }
        
        if(myMap2.find(str2[i]) == myMap2.end()) {
            pair<char, int> myPair;
            myPair = make_pair(str2[i], 1);
            myMap2.insert(myPair);
        } else {
            myMap2.at(str2[i])++;
        }
    }
    
    //check if both maps have the same character counts
    //if that's not the case the two strings are not permutations of each other
    for (int i=0; i<str1.size(); i++){
        if(myMap1[str1[i]] != myMap2[str1[i]]){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}

//second solution - sort the 2 strings and check that sorted strings are equal
void sort_strings(string str1, string str2) {
    
    //check if the strings have the same length
    if(str1.size() != str2.size()){
        cout << "no" << endl;
        return;
    }
    
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    
    for(int i=0; i<str1.size(); i++){
        
        if(str1[i] != str2[i]){
            cout << "no" << endl;
            return;
        }
    }
    cout << "yes" << endl;
}





int main() {
    
    string str1 = "qpqqwttturewte";
    string str2 = "ottttwerqweuqq";
    
    check_character_counts(str1, str2);
    cout << endl;
    sort_strings(str1, str2);
    
    return 0;
}

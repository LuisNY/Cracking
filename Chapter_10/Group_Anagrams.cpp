#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_multimap;
using std::pair;


//unordered_multimap structure is used (hash table where multiple values can have the same key)
//all strings are ordered (so that all anagrams will have the same key) and then inserted into the unordered_multimap using the ordered version as a key.
//finally search through the unordered_multimap and put all strings into a vector. All anagrams will be found next to each other thanks to their key.

int main(){
    
    vector<string> myVect = {"ace", "acre", "oicm", "eca", "care", "race", "rac", "aec", "mico", "moci"};
    
    vector<string> outVect;
    
    unordered_multimap<string, string> myHashStructure;
    
    for(int i=0; i<myVect.size(); i++){
        
        string tempStr = myVect[i];
        
        std::sort(tempStr.begin(), tempStr.end());
        
        pair<string, string> myPair = std::make_pair(tempStr, myVect[i]);
        
        myHashStructure.insert(myPair);
    }
    
    
    for(auto& x: myHashStructure){
        outVect.push_back(x.second);
    }
    
    for (int i=0; i<outVect.size(); i++)
        cout << outVect[i] << endl;
    
    cout << myHashStructure.size() << endl;
    
    
    
    return 0;
}

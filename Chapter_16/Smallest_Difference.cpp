#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
using std::endl;
using std::cout;
using std::cin;
using std::set;
using std::queue;


struct couple{
    int elem1;
    int elem2;
};

struct couple smallestDiff(vector<int> array1, vector<int> array2){
    
    int minDiff=INT_MAX;
    
    struct couple myCouple;
    
    std::sort(array1.begin(), array1.end());
    std::sort(array2.begin(), array2.end());
    
    myCouple.elem1=array1[0];
    myCouple.elem2=array2[0];
    int i=0;
    int j=0;
    while(i<(int)array1.size() && j<(int)array2.size()){
        
        int diff = abs(array1[i]-array2[j]);
        
        if(diff<minDiff){
            
            myCouple.elem1 = array1[i];
            myCouple.elem2 = array2[j];
            minDiff=diff;
            cout << "new min diff " << minDiff << endl;
        }
           
        
        if(array1[i]<array2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    
    return myCouple;
}


int main() {

    vector<int> array1 = {8, 20, 23, 127, 135, 300, 700};
    vector<int> array2 = {1, 2, 3, 11, 15, 16, 701, 800};

    struct couple myCouple;
    myCouple = smallestDiff(array1, array2);
    
    cout << myCouple.elem1 << " " << myCouple.elem2 << endl;
    
    
    return 0;
}

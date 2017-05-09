#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

using std::cout;
using std::cin;
using std::endl;
using std::vector;


int binarySearch(const vector<int>& myVect, int start, int end, int x) {
    
    
    int middle = (start+end)/2;
    if(x==myVect[middle])
        return middle;
    
    if(start>end)
        return -1;
    
    if(x>myVect[middle])
        return binarySearch(myVect, middle+1, end, x);
    
    else
        return binarySearch(myVect, start, middle-1, x);
    
}


int modifiedBinarySearch(const vector<string>& myVect, int start, int end, string str){
    
    if(start>end)
        return -1;
    
    int mid = (start+end)/2;
    
    if(myVect[mid] == ""){
        
        int left = mid-1;
        int right = mid+1;
        
        while(1){
            
            if(left > start && myVect[left] != ""){
                mid = left;
                break;
            }
            if(right < end && myVect[right] != ""){
                mid = right;
                break;
            }
            if(left<start && right>end){
                return -1;
            }
            
            right++;
            left--;
        }
    }
    
    if(str.compare(myVect[mid]) == 0)
        return mid;
    
    if(str.compare(myVect[mid]) > 0)
        return modifiedBinarySearch(myVect, mid+1, end, str);
    
    else
        return modifiedBinarySearch(myVect, start, mid-1, str);

    
    return 0;
}




int main(){
    
    
    vector<string> myVect = {"", "", "boring", "cab", "", "car", "", "", "", "mike", "mine", "", "taxi"};
    string str;
    cout << "insert string to search " << endl;
    cin >> str;
    
    
    cout << modifiedBinarySearch(myVect, 0, (int)myVect.size(), str) << endl;
    
    
    return 0;
}

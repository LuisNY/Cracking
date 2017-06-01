string binaryString(int x){
    
    string myString;
    
    int count=0;
    
    int temp=x;
    while(temp>0){
        temp/=2;
        count++;
    }
    
    count--;
    int sum=0;
    while(sum<x){
        if(sum+pow(2, count)<=x){
            sum+=pow(2, count);
            myString.append("1");
        }
        else
           myString.append("0");
    
        count--;
    }
    while(count>=0){
        myString.append("0");
        count--;
    }

    return myString;
}



int main() {
    
    int x=65;
    
    cout << binaryString(x) << endl;
    
    return 0;
}

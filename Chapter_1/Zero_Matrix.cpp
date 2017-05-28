#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
using std::endl;
using std::cout;
using std::cin;

void zeroMatrix(int** matrix, int N, int M){
    
    bool rows[N];
    for(int i=0; i<N; i++)
        rows[i] = false;
    
    bool cols[M];
    for(int i=0; i<M; i++)
        cols[i] = false;
    
    for(int i=0; i<N; i++){
        
        for(int j=0; j<M; j++){
            
            if(rows[i])
                continue;
            if(cols[j])
                continue;
            if(matrix[i][j]==0){
                
                rows[i]=true;
                cols[j]=true;

                for(int k=0; k<N; k++){
                    
                    matrix[k][j]=0;
                }
                
                for(int k=0; k<M; k++){
                    
                    matrix[i][k]=0;
                }
            }
        }
    }
    return;
}


int main() {
    
    int N=5;
    int M=5;
    int** matrix;
    
    matrix = new int* [N];
    for(int i=0; i<N; i++){
    
        matrix[i] = new int[M];
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            matrix[i][j] = i+j;
        }
    }
    
    matrix[2][3] = 0;
    
    zeroMatrix(matrix, N, M);
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

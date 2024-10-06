#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool areEqualRows(int* arr1, int* arr2, int size) {  
    for(int i = 0; i < size; i++) {
        if(arr1[i] != arr2[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    int arr[N][M];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    
    int counter = 0;
    for(int i = 0; i < N; i++) {
        bool hasEqual = false;
        for(int j = 0; j < N; j++) {
            if(j != i && areEqualRows(arr[i], arr[j], M)) {
               hasEqual  = true;
               break;
            }
        }
        
        if(!hasEqual) {
            counter++;
        }
    }  
    
    cout << counter;
    
    return 0;
}

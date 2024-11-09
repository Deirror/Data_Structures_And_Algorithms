#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }   
    //
        int days = 0;
        stack<int> st;     
        for(int i = 0; i < n; i++) {
            int counter = 0;
            int minCounter = 0;
            while(st.size() && arr[st.top()] < arr[i] && i < n) {          
                if(arr[i] < arr[i - 1]) {
                     minCounter++;
                }       
                counter++;
                i++;
            }
            if(counter > 0) {
                if(counter == minCounter == 1) minCounter = 0;
                days = max(days, counter - (counter - minCounter) + 1);
            }
            st.push(i);      
        }        
    //
    cout << days;
    return 0;
}

#include <cmath>
#include <deque>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;   
    
    vector<deque<int>> groups(n);  
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    bool prev = nums[0] > 0;
    int idx = 0;
    int size = 1;
    for(auto num : nums) {
        bool flag = num > 0;
        if(flag != prev) {
            idx++;
            size++;
        }
        groups[idx].push_back(num);
        prev = flag;
    }
    
    for(int i = 0; i < size - 1; i++) {
        if(groups[i].front() > 0 && groups[i + 1].front() < 0) {
            while(groups[i].size() && groups[i + 1].size()) {
              if(groups[i].front() == groups[i + 1].back() * (-1)) {
                  groups[i].pop_back();
                  groups[i+1].pop_front();
              } else if(groups[i].front() > groups[i + 1].back() * (-1)){
                  groups[i+1].pop_front();
              } else {
                  groups[i].pop_back();
              }
            }      
        }    
    }
    
    bool flag = false;
    for(int i = 0; i < size; i++) {
        while(groups[i].size()) {
            cout << groups[i].back() << ' ';
            groups[i].pop_front();
            flag = true;
        }
    }
    if(!flag) {
        cout <<'\n';
    }
    
    return 0;
}

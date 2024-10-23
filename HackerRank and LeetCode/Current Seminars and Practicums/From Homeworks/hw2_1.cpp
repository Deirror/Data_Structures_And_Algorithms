#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long invited[int(1e5)]{};//max char can be log3(3^33) = 33

void calc_candys(vector<char>& all, int l, int r, int rec_level = 1) {
    if(l >= r || rec_level == 32) {//one element, max rec level
        all[r] = rec_level;
        return;
    }
    
    int fh_mid = l + (r - l) / 3;
    int sc_mid = r - (r - l) / 3;    
    
    for(int i = fh_mid + 1; i < sc_mid; i++) {
        all[i] = rec_level;
    }
    
    rec_level++;
    calc_candys(all, l, fh_mid, rec_level);
    calc_candys(all, sc_mid, r, rec_level);
}

vector<char> all;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int p, n;
    cin >> p >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> invited[i];//must be between 1 and 3^p
    }
    
    long long size = pow(3,p);
    all.resize(size + 1);
    
    calc_candys(all, 1, size);
    
    for(int i = 0; i < n; i++) {
        cout << int(all[invited[i]]) << '\n';
    }
    
    return 0;
}

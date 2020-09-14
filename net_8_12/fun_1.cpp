/*
七星不靠

147, 258, 369
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int T;
    cin >> T;
    string str[7];
    int p[7];
    unordered_set<char> sets;

    while (T --) {
        sets.clear();
        for (int i = 1; i < 7; i ++) 
        for (int i = 0; i < 7; i ++) cin >> str[i];
        
        for (int i = 0; i < 7; i ++) {
            char y = str[i][1];
            sets.insert(y);
        }

        if (sets.size() < 3) cout << "NO" << endl;
        else {
            
        }
    }
    return 0;
}
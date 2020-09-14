#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("meituan_8_29/in_1.txt", "r", stdin);
    //freopen("meituan_8_29/out_1.txt", "w", stdout);
    
    int n;
    string str;
    cin >> n >> str;

    int left = -1, right = -1;
    unordered_map<char, int> hash;
    for (int i = 0; i < n; i ++) {
        hash[str[i]] ++;
        if (str[i] == 'T' && hash.count('M')) {
            left = i + 1;
            break;
        }
    }

    hash.clear();
    for (int i = n; i >= 0; i --) {
        hash[str[i]] ++;
        if (str[i] == 'M' && hash.count('T')) {
            right = i - 1;
            break;
        }
    }
    cout << str.substr(left, right - left + 1) << endl;
    return 0;
}
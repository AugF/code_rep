#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("xhs_8_30/in_1.txt", "r", stdin);
    freopen("xhs_8_30/out_1.txt", "w", stdout);
    string str;
    int t = 1;
    while (getline(cin, str, '\n')) {
        int n = str.size();
        if (n <= 1024) cout << "msg" << t << ":" << str << endl, t ++;
        else {
            int len = 0, st = 0;
            for (int i = 0; i < n; i ++) {
                int j = i;
                while (j < n && str[j] != '.' && str[j] != '!') j ++;
                // cout << 'x' << j - i << endl;
                if (len + j - i <= 1024) {
                    len += j - i + 1;
                } else {
                    cout << "msg" << t << ":" << str.substr(st, len) << endl;
                    len = j - i + 1, st = i, t ++;
                }
                i = j;
            }
        }
    }
    return 0;
}
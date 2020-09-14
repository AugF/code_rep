#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("ali_8_26/in_1.txt", "r", stdin);
    freopen("ali_8_26/out_1.txt", "w", stdout);
    int T;
    cin >> T;
    while (T --) {
        string a, b;
        int n;
        cin >> n >> a >> b;
        int res = 0;
        if (a >= b) cout << res << endl;
        else {
            vector<int> tmp(n, 0);
            tmp[0] = 1;
            for (int i = 1; i < n; i ++) tmp[i] = tmp[i - 1] * 26;

            res += max(0, b[0] - a[0] - 1) * tmp[n - 1];

            // cout << 't' << res << endl;
            // 加上大于a的数
            for (int i = 1; i < n; i ++) {
                res += ('z' - a[i]) * tmp[i - 1];
            }
            // cout << 't' << res << endl;

            // 加上小于b的数 
            for (int i = 1; i < n; i ++) {
                res += (b[i] - 'a') * tmp[i - 1];
            }
            cout << res << endl;
        }
    }
}
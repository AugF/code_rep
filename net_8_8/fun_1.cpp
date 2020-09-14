#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("net_8_8/data/in_1.txt", "r", stdin);
    freopen("net_8_8/data/out_1.txt", "w", stdout);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int res = 0;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        if (x > 1) res += x / 2; 
    }
    cout << res << endl;
    return 0;
}
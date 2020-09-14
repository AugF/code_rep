#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("zhaoyin_8_3/data/in_2.txt", "r", stdin);
    freopen("zhaoyin_8_3/data/out_2.txt", "w", stdout);
    int n, k;
    cin >> n >> k;

    if ((k == 1 && n > 1) || n < k) {
        cout << "-1" << endl;
        return 0;
    }

    string res;
    int m = n - (k - 2);
    while (m --) {
        res += 'a';
        m --;
        if (!m) break;
        res += 'b';
    }

    for (int i = 2; i < k; i ++) res += 'a' + i;
    cout << res << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// https://www.nowcoder.com/discuss/465066
// 
int main() {
    freopen("pdd_8_2/data/in_1.txt", "r", stdin);
    freopen("pdd_8_2/data/out_1.txt", "w", stdout);
    int target, cnt;
    cin >> target >> cnt;

    int s = 0, reverse = 0, res = INT_MAX; // LLONG_MIN
    while (cnt --) {
        int x;
        cin >> x;
        s += x;
        if (s > target) s = target - (s - target), reverse ++;
        res = min(res, target - s);
    }

    if (s == target) cout << "paradox" << endl;
    else cout << res << ' ' << reverse << endl;
    // system("pause");
    return 0;
}
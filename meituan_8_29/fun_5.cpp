#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("meituan_8_29/in_5.txt", "r", stdin);
    //freopen("meituan_8_29/out_5.txt", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> nums(n + 1), ans(n + 1);
    
    for (int i = 1; i <= n; i ++) cin >> nums[i], ans[i] = -1;

    int m;
    cin >> m;
    while (m --) {
        int p;
        cin >> p;
        if (p == 1) {
            int k, x, y;
            cin >> k >> x >> y;
            while (k --) ans[y ++] = nums[x ++];
        } else if (p == 2) {
            int x;
            cin >> x;
            cout << ans[x] << endl;
        }
    }
    return 0;
}

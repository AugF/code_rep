//
#include <bits/stdc++.h>
using namespace std;

int find(int x, vector<int>& p) {
    if (x != p[x]) p[x] = find(p[x], p);
    return p[x];
}

int main() {
    freopen("meituan_8_22/in_3.txt", "r", stdin);
    freopen("meituan_8_22/out_3.txt", "w", stdout);
    int T;
    cin >> T;

    while (T --) {
        int n;
        cin >> n;
        vector<int> sum(n + 1), b(n + 1), L(n + 1), R(n + 1), res(n + 1), p(n + 1);
        for (int i = 1; i <= n; i ++) {
            int x;
            cin >> x;
            sum[i] = sum[i - 1] + x;
            p[x] = x;
        }

        for (int i = 1; i <= n; i ++) cin >> b[i];
        for (int i = n; i >= 1; i --) {
            int x = b[i];
            L[x] = R[x] = x; // 为当前初始化
            if (x + 1 <= n) { // 为右边扩大领域
                int px = find(x + 1, p);
                p[x] =px;
                R[px] = max(R[px], R[x]);
                L[px] = min(L[px], L[x]);
                x = px;
            }

            if (x - 1 >= 1) { // 为左边扩大领域
                int px = find(x - 1, p);
                p[x] = px;
                R[px] = max(R[px], R[x]);
                L[px] = min(L[px], L[x]);
                x = px;
            }
            if (i < n) 
                res[i] = max(res[i + 1], sum[R[x]] - sum[L[x] - 1]);
        }
        for (int i = 1; i <= n; i ++) cout << res[i] << ' ';
        cout << endl;
    }
}
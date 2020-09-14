// 一个简单的整数问题 https://www.acwing.com/problem/content/248/
#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5 + 10;

int n, m;
int a[N], tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

int query(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) ans += tr[i];
    return ans;
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) cin >> a[i];
    
    for (int i = 1; i <= n; i ++) add(i, a[i] - a[i - 1]);
    
    while (m --) {
        char op[2];
        cin >> op;
        if (op[0] == 'Q') {
            int x;
            cin >> x;
            cout << query(x) << endl;
        } else {
            int l, r, d;
            cin >> l >> r >> d;
            add(l, d), add(r + 1, -d);
        }
    }
    return 0;
}
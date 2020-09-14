#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5, M = N * 2;

int n, m, x, y;
int h[N], e[M], ne[M], idx;
bool st[N];
int ans = 0;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u, int fa) {
    st[u] = true;
    int max_temp = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == fa) continue;
        if (!st[j])
            max_temp = max(max_temp, dfs(j, u));
    }
    return max_temp + 1;
}

int main() {
    // dx > dy, 情况下的全局最大值
    //freopen("meituan_8_29/in_3.txt", "r", stdin);
    //freopen("meituan_8_29/out_3.txt", "w", stdout);
    
    cin >> n >> x >> y;
    memset(h, -1, sizeof h);
    idx = 0;

    for (int i = 0; i < n - 1; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    cout << dfs(x, -1) - 1 << endl;
    return 0;
}
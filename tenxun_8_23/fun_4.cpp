#include <bits/stdc++.h>
#define ONLINE
using namespace std;
using LL = long long;

const int maxn = 5050;
int n;
int a[maxn];
int f[maxn][maxn];

int dfs(int l, int r) { // 竖着刷
    if (l > r) return 0;
    if (~f[l][r]) return f[l][r];
    int k = l;
    for (int i = l + 1; i <= r; i ++)
        if (a[i] < a[k]) k = i;
    
    int ret = a[k];
    for (int i = l; i <= r; i ++) a[i] -= ret;
    return f[l][r] = min(r - l + 1, dfs(l, k - 1) + dfs(k + 1, r) + ret);
}

int main() {
#ifndef ONLINE
    freopen("tenxu_8_23/in_1.txt", "r", stdin);
    freopen("tenxu_8_23/out_1.txt", "w", stdout);
#endif
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        memset(f, -1, sizeof f);
        printf("%d\n", dfs(1, n));
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long lolo;
const int maxn = (int)1e5 + 5;

int w[maxn], p[maxn], q[maxn], L[maxn], R[maxn];
lolo sum[maxn], ans[maxn];
int findp(int x) {
    return p[x] == x?x:findp(p[x]);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", w+i);
        sum[i] = sum[i-1] + w[i];
        p[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", q+i);
    }
    for (int i = n-1; i > 0; --i) {
        int x = q[i];
        p[x] = L[x] = R[x] = x;
        if (x-1 >=1 && p[x-1] != -1) {
            int r = findp(x-1);
            p[x] = r;
            L[r] = min(L[r], L[x]);
            R[r] = max(R[r], R[x]);
            x = r;
        }
        if (x+1 <= n && p[x+1] != -1) {
            int r = findp(x+1);
            p[x] = r;
            L[r] = min(L[r], L[x]);
            R[r] = max(R[r], R[x]);
            x = r;
        }
        ans[i-1] = max(ans[i], sum[R[x]] - sum[L[x]-1]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%lld\n", ans[i]);
    }
//    system("pause");
    return 0;
}
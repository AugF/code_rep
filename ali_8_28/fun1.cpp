#include <bits/stdc++.h>
using namespace std;
typedef long long lolo;

const int maxn = 1e6 + 5;

int cnt[11], n;
int m, ans;

void dfs(int u, int cur) {
    if (u == n) {
        if (cur % m) ++ ans;
        return;
    }

    for (int i = u > 0?0: 1; i < 10; ++ i) {
        if (cnt[i] > 0) {
            -- cnt[i];
            dfs(u + 1, cur * 10 + i);
            ++ cnt[i];
        }
    } 
}

int main() {
    char s[20];
    scanf("%s%d", s, &m);
    n = strlen(s);
    for (int i = 9; i < n; ++ i) {
        cnt[s[i] - '0'] ++;
    }
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;    
}
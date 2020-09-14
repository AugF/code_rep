#include <bits/stdc++.h>
using namespace std;
int n, m;

int main() {
    // freopen("net_8_8/data/in_4.txt", "r", stdin);
    // freopen("net_8_8/data/out_4.txt", "w", stdout);
    
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }

    for (int k = 1; k <= n; k ++) {
        for (int i = 1; i <= n; i ++)
            for (int j = 1; j <= n; j ++) {
                if (g[i][k] && g[k][j])
                    g[i][j] = true;
            }
    }

    int res = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++)
            if (g[i][j] && g[j][i]) res ++;
    cout << res << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int g[N][N], n, m, s;

bool dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (x == n - 1 && y == m - 1) return true;

    if (g[x + s][y] && dfs(x + s, y)) return true;
    if (g[x][y + s] && dfs(x, y + s)) return true; 
    return false;
}

int main() {
    freopen("huawei_8_12/data/in_2.txt", "r", stdin);
    freopen("huawei_8_12/data/out_2.txt", "w", stdout);
    cin >> s >> n >> m;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            cin >> g[i][j];
    cout << dfs(0, 0) << endl;
    return 0;
}
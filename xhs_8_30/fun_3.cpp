#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int a[N][N], abs_row[N][N], abs_col[N][N]; // abs_row[i][j]: 表示第i行前j列的差值和;  abs_col[i][j]: 表示第i列前i行的差值和

int main() {
    int n, m, r, c;
    cin >> n >> m >> r >> c;

    // dp[i][j]: 从前i列中选j列的最大代价, 第j列必选
    // abs(): 每列的差值，预处理
    // abs(): 每行的差值，预处理
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            cin >> a[i][j];

    for (int i = 0; i < n; i ++) {
        for (int j = 1; j <= m; j ++)
            abs_row[i][j] = abs_row[i][j - 1] + abs(a[i][j] - a[i][j - 1]);
    }

    for (int j = 0; j < m; j ++)
        for (int i = 1; i <= n; i ++)
            abs_col[j][i] = abs_col[j][i - 1] + abs(a[j][i] - a[j][i - 1]);
    
    // dp[i][j] = max(dp[i-1][j], dp[k][j-1] + 第j列选的代价)  
    // dfs(k, n)
    // 一定要复习最简单的回溯模板
}
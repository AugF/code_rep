// 写代码规范一点
#include <bits/stdc++.h>
using namespace std;
const int N = 102, M = 1002;
int a[N][M], sum[N][M];
int arr[N];

// 环形最大子矩阵和，时间复杂度O(N*M^2)
// 思路: 整合列的子段和（双指针枚举所有可能的起始位置和终止位置），将其表示为行的某个值；然后，对行求一维子数组和
int main() {
    freopen("yuan_8_22/in_2.txt", "r", stdin);
    freopen("yuan_8_22/out_2.txt", "w", stdout);

    int n, m;
    // n: 100, m: 1000
    cin >> n >> m;
    
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++)
            cin >> a[i][j];

    // 维护前缀和
    for (int i = 0; i < n; i ++) {
        for (int j = 1; j <= m; j ++) sum[i][j] = sum[i][j - 1] + a[i][j - 1];
        for (int j = m + 1; j <= 2 * m; j ++) sum[i][j] = sum[i][j - 1] + a[i][j - m - 1];
    }


    // i,j是列，按行凑小矩形; O(M*M*N)
    int res = INT_MIN;
    for (int i = 1; i <= m; i ++) { // 枚举i
        memset(arr, 0, sizeof arr);
        for (int j = i; j < i + m; j ++) {
            for (int k = 0; k < n; k ++) arr[k] = sum[k][j] - sum[k][i - 1];
            // 求最大子数组
            int tmp_max = 0, cur = 0; 
            for (int k = 0; k < n; k ++) {
                cur = max(cur + arr[k], arr[k]);
                tmp_max = max(tmp_max, cur);
            }
            res = max(res, tmp_max);
        }
    }

    cout << res << endl;
    return 0;
}
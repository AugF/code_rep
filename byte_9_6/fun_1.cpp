#include <bits/stdc++.h>
using namespace std;

// f[i][0]: 第i个阶梯走1步的走法; f[i][1]: 第i个阶梯走两步的走法
// f[i][0] = f[i - 1][0] + f[i - 1][1] 
// f[i][1] = f[i - 2][0]  第i个阶梯走两步的走法的上一步只能走1步
// 初始化 f[0][0] = 1;
// res = (f[n][0] + f[n][1])

int main() { 
    int n;
    cin >> n;
    vector<vector<int>> f(n + 1, vector<int>(2, 0));
    f[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        f[i][0] = f[i - 1][0] + f[i - 1][1];
        if (i >= 2) f[i][1] = f[i - 2][0];
    }
    cout << f[n][0] + f[n][1] << endl;
    system("pause");
    return 0;
}
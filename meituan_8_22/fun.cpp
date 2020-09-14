#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;
    
    vector<vector<int>> f(n + 1, vector<int>(k + 1, 0)); // 从前k个数中选，结果为n的方案数
    
    // f[i][k] = f[i][k] + f[i-k][k-1
    for (int i = 0; i <= k; i ++) f[0][k] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = )
    }
}
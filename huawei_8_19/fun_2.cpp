// c(i, j) = c(i - 1, j) + c(i, j - 1)
#include <bits/stdc++.h>
using namespace std;
const int N = 1001, MOD = 1e9 + 7;
int c[N][N];

void preprocess() {
    c[0][0] = 1;
    for (int i = 1; i < N; i ++)
        for (int j = 0; j <= i; j ++)
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
}

int main() {
    preprocess();
    
    int n, x;
    cin >> n;
    int max_h = 0;
    unordered_map<int, int> hash;
    while (n --) {
        cin >> x;
        hash[x] ++;
        max_h = max(max_h, x);
    }

    int res = 1;
    for (int i = 1; i <= max_h; i ++) {
        // cout << i << ' ' << hash[i] << ' ' << c[2 * hash[i-1]][hash[i]] << endl;
        res = ((long long)res * c[2 * hash[i-1]][hash[i]]) % MOD;
    }
    cout << res << endl;
    system("pause");
    return 0;
}
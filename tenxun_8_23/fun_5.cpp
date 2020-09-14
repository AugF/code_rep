// f[i,j]: 最少的次数
// f[i,j] = min(f[i, j], f[i, k] + f[k+1, j])
// if (p[i, j]) f[i,j]=1;
#include <bits/stdc++.h>
using namespace std;
const int N = 402;
bool p[N][N];
int f[N][N];

string str;
int n;

int main() {
    //freopen("tenxun_8_23/in_5.txt", "r", stdin);
    //freopen("tenxun_8_23/out_5.txt", "w", stdout);
    cin >> str;
    n = str.size();
    
    // p[i,j]，即判断i-j是否为回文串
    for (int len = 1; len <= n; len ++) {
        for (int l = 0; l + len - 1 < n; l ++) {
            int r = l + len - 1;
            // 计算p[l][r]
            if (len == 1) p[l][r] = true;
            else if (len == 2) p[l][r] = str[l] == str[r];
            else {
                p[l][r] = str[l] == str[r] && p[l + 1][r - 1];
            }

            // 计算f[l][r]
            if (p[l][r]) {
                f[l][r] = 1;
                continue;
            }

            f[l][r] = INT_MAX;
            for (int k = l; k < r; k ++)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
        }
    }

    int q;
    cin >> q;
    while (q --) {
        int l, r;
        cin >> l >> r;
        cout << f[l - 1][r - 1] << endl;
    }
    return 0;
}




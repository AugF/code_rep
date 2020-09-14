#include <bits/stdc++.h>
using namespace std;
const int N = 110;

char a[N], b[N];
int f[N][N];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++) cin >> a[i];
    for (int i = 0; i < n; i ++) cin >> b[i];

    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) {
            if (a[i - 1] == b[j - 1]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    
    double x = f[n][n] * 1.0 / n;
    string success = (x <= 0.5)? "Yes": "No";
    printf("%.2f", x);
    return 0;
}

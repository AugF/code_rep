#include <bits/stdc++.h>
using namespace std;
const int N = 302;
int w[N][N], ans[N];
bool st[N];

int main() {
    //freopen("meituan_8_29/in_2.txt", "r", stdin);
    //freopen("meituan_8_29/out_2.txt", "w", stdout);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            cin >> w[i][j];
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (!st[w[i][j]]) {
                st[w[i][j]] = true;
                ans[i] = w[i][j];
                break;
            }
        }
    }

    for (int i = 0; i < n; i ++) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
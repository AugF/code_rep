#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int g[N][N];

int get(int x1, int y1, int x2, int y2) {
    return g[x2][y2] - g[x1 - 1][y2] - g[x2][y1 - 1] + g[x1 - 1][y1 - 1];
}

int main() {
    freopen("netwase_pra/data/in_1.txt", "r", stdin);
    freopen("netwase_pra/data/out_1.txt", "w", stdout);
    int t;
    cin >> t;

    while (t --) {
        memset(g, 0, sizeof g);
        int n, m, k, x, y;
        cin >> n >> m >> k;
        while (k --) {
            int a1, a2;
            cin >> a1 >> a2;
            g[a1][a2] = 1;
        }
        cin >> x >> y;

        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
                // cout << g[i][j] << ' ';
            }
            // cout << endl;
        }

        for (int i = n; i >= 1; i --) {
            for (int j = 1; j <= m; j ++) {
                cout << g[i][j] << ' ';
            }
            cout << endl;
        }


        bool flag = true;
        for (int i = 1; i + x - 1 <= n && flag; i ++)
            for (int j = 1; j + y - 1 <= m; j ++) {
                int t = get(i, j, i + x - 1, j + y - 1);
                if (t == 0) {
                    int x1 = i, y1 = j, x2 = i + x - 1, y2 = j + y - 1;
                    cout << g[x2][y2] << ' ' << g[x2][y1 - 1] << ' ' << g[x1 - 1][y2] << ' ' << g[x1 - 1][y1 - 1] << endl;
                    flag = false;
                    break;
                }
            }
        cout << (flag? "NO": "YES") << endl;
    }
    return 0;
}
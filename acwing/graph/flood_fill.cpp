/*
Flood Fill问题
求连通分支的数目

*/
#include <iostream>
#include <cstring>
#include <algorithm>
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n, m;
char g[N][N];
PII q[M]; // 队列
bool st[N][N]; // 标记数组，可以保证是线性的

void bfs(int sx, int sy) {
    int hh = 0, tt = -1;
    q[++ tt] = {sx, sy};
    st[sx][sy] = true;

    while (hh <= tt) {
        PII t = q[hh ++];

        for (int i = t.x - 1; i <= t.x + 1; i ++)
            for (int j = t.y - 1; j <= t.y + 1; j ++) {
                if (i == t.x && j == t.y) continue;
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                if (g[i][j] == '.' || st[i][j]) continue;

                q[++ tt] = {i, j};
                st[i][j] = true;
            }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) scanf("%s", g[i]);

    int cnt = 0;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++) {
            if (g[i][j] == 'W' && !st[i][j]) {
                bfs(i, j);
                cnt ++;
            }
        }
    cout << cnt << endl;
    return 0;
}


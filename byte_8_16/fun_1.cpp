#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
int n, pre[N], cur[N];
unordered_map<int, int> maps;
int res;

void dfs(int pl, int pr, int cl, int cr) {

}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> pre[i];
    for (int i = 0; i < n; i ++) cin >> cur[i];

    res = 0;
    maps.clear();
    for (int i = 0; i < n; i ++) maps[cur[i]] = i;
    dfs(0, n - 1, 0, n - 1);
    cout << res << endl;
    return 0;    
}
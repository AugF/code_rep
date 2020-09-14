#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1010;
LL f[N];

int main() {
    freopen("sf_8_20/in_2.txt", "r", stdin);
    freopen("sf_8_20/out_2.txt", "w", stdout);
    int T;
    cin >> T;
    while (T --) {
        memset(f, 0, sizeof f);

        int n;
        cin >> n;
        vector<vector<int>> tasks(n);
        for (int i = 0; i < n; i ++) {
            int x, y, z;
            cin >> x >> y >> z;
            tasks[i] = {x, y, z};
        }

        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] != b[0]) return a[0] < b[0];
            if (a[1] != b[1]) return a[1] < b[1];
            return a[2] < b[2];
        });

        LL res = INT_MIN;
        for (int i = 0; i < n; i ++) {
            int x = tasks[i][0], w = tasks[i][2];
            f[i] = w;
            for (int j = i - 1; j >= 0; j --) {
                int r = tasks[j][1];
                if (r < x) f[i] = max(f[i], f[j] + w); 
            }
            res = max(res, f[i]);
        }
        cout << res << endl;
    }
    return 0;
}
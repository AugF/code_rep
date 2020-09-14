#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    freopen("huawei_8_19/in_3.txt", "r", stdin);
    freopen("huawei_8_19/out_3.txt", "w", stdout);
    cin >> T;
    while (T --) {
        string a, b;
        cin >> a >> b;
        vector<int> frames_a, frames_b;

        int n = a.size(), d = b.size(), min_a = INT_MAX;    
        for (int i = 0; i < n; i ++) {
            int h = a[i] - '0';
            frames_a.push_back(h);
            min_a = min(min_a, h);
        }
        
        // 1. 预处理，如果所有的都大于非零值，那么可以减去非零值
        if (min_a) {
            for (int i = 0; i < n; i ++) frames_a[i] -= min_a;
        }

        for (int i = 0; i < d; i ++) frames_b.push_back(b[i] - '0');

        // for (auto x: frames_a) cout << x << ' ';
        // cout << endl;

        // for (auto x: frames_b) cout << x << ' ';
        // cout << endl;

        // 2. 记录最合适的位置；最合适的位置，应该是brick放置的最高高度最低
        int min_i = 0, min_h = INT_MAX;
        for (int i = 0; i + d <= n; i ++) {
            int tmp = INT_MIN;
            for (int j = 0; j < d; j ++) tmp = max(tmp, frames_a[i + j] + frames_b[j]);
            // cout << 't' << tmp << endl;
            if (tmp < min_h) {
                min_i = i, min_h = tmp;
            }
        }

        // 3. 按高度还原; brick从高到低还原，frame从低到高还原
        vector<vector<int>> maps(n, vector<int>(min_h, 0));
        for (int i = 0; i < n; i ++) {
            int j = -1, k = frames_a[i];
            while (k --) maps[i][++ j] = 1;
            if (i >= min_i && i < min_i + d) {
                j = min_h, k = frames_b[i - min_i];
                while (k --) maps[i][-- j] = 1;
            }
        }

        for (auto x: maps) {
            for (auto y: x)
                cout << y << ' ';
            cout << endl;
        }

        // 4. 记录结果
        int res = min_a;
        for (int i = 0; i < min_h; i ++) {
            bool flag = true;
            for (int j = 0; j < n; j ++) {
                if (!maps[j][i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ++ res;
        }
        cout << min_h - res << endl;
        cout << endl;
    }
    return 0;
}
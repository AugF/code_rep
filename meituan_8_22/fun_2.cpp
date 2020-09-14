#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("meituan_8_22/in_2.txt", "r", stdin);
    freopen("meituan_8_22/out_2.txt", "w", stdout);
    int T;
    cin >> T;
    while (T --) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> products;
        for (int i = 1; i <= n; i ++) {
            int v, w;
            cin >> v >> w;
            products.push_back({v + w * 2, i});
        }

        sort(products.begin(), products.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] <= b[1];
        });
        
        vector<int> res;
        for (int i = 0; i < m; i ++) res.push_back(products[i][1]);
        sort(res.begin(), res.end());
        for (auto x: res) cout << x << ' ';
        cout << endl;
    }
    return 0;
}
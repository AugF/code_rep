#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("zhaoyin_8_3/data/in_1.txt", "r", stdin);
    freopen("zhaoyin_8_3/data/out_1.txt", "w", stdout);
    int n;
    cin >> n;

    string maps[] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001"};
    while (n --) {
        string x, res;
        cin >> x;
        int k = 3 - x.size();
        while (k --) res += maps[0];
        for (int i = 0; i < x.size(); i ++) {
            int p = x[i] - '0';
            res += maps[p];
        }
        while (res.size() > 1 && res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
}
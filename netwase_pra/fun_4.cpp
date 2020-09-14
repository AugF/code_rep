#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[N];

int main() {
    // freopen("netwase_pra/data/in_4.txt", "r", stdin);
    // freopen("netwase_pra/data/out_4.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    vector<int> f(n, INT_MAX);

    int i = 0;
    bool flag = true;
    while (i < n) {
        int max_val = INT_MIN;
        for (int k = i; k < n; k ++) {
            max_val = max(max_val, a[k]);
            f[k - i] = min(f[k - i], max_val);
        }
        i ++;
    }

    for (int i = 0; i < n; i ++) cout << f[i] << ' ';
    cout << endl;
    return 0;
}
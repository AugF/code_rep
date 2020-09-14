#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], n, q;

int main() {
    freopen("netwase_pra/data/in_2.txt", "r", stdin);
    freopen("netwase_pra/data/out_2.txt", "w", stdout);

    cin >> n >> q;
    for (int i = 0; i < n; i ++) cin >> a[i];

    sort(a, a + n);
    while (q --) {
        int x;
        cin >> x;
        int cnt = 0;
        for (int i = n - 1; i >= 0; i --) {
            if (a[i] >= x) {
                cnt ++; 
                a[i] --;
            } else break;
        }
        cout << cnt << endl;
    }
    return 0;
}
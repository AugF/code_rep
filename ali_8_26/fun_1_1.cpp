#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("ali_8_26/in_1.txt", "r", stdin);
    //freopen("ali_8_26/out_1.txt", "w", stdout);
    int T;
    cin >> T;
    while (T --) {
        string a, b;
        int n;
        cin >> n >> a >> b;
        if (a >= b) cout << '0' << endl;
        else {
            long long res_a = 0, res_b = 0, t = 1;
            for (int i = n - 1; i >= 0; i --) {
                res_a += t * (a[i] - 'a' + 1);
                res_b += t * (b[i] - 'a' + 1);
                t *= 26;
            }
            cout << res_b - res_a - 1 << endl;
        }
    }
    return 0;
}
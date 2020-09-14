#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("net_8_8/data/in_2.txt", "r", stdin);
    //freopen("net_8_8/data/out_2.txt", "w", stdout);
    int T;
    cin >> T;
    
    int n;
    vector<int> a, b, f;
    while (T --) {
        a.clear(), b.clear(), f.clear();
        cin >> n;
        a.resize(n + 1), b.resize(n);
        for (int i = 1; i <= n; i ++) cin >> a[i];
        for (int i = 1; i <= n - 1; i ++) cin >> b[i];

        f.resize(n + 1, INT_MAX);
        if (n == 0) {
            cout << "08:00:00 am" << endl;
            continue;
        }
        f[0] = 0, f[1] = a[1];
        for (int i = 2; i <= n; i ++)
            f[i] = min(f[i - 1] + a[i], f[i - 2] + b[i - 1]);
        
        int hours = f[n] / 3600, minutes = (f[n] % 3600) / 60;
        int seconds = (f[n] % 3600) % 60;
        string end_tag = hours >= 5? "pm": "am";
        hours = (hours + 8) % 12;
        printf("%.2d:%.2d:%.2d %s\n", hours, minutes, seconds, end_tag.c_str());
    }
    return 0;
}
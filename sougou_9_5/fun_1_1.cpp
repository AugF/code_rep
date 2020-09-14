#include <bits/stdc++.h>
using namespace std;

long long fun(long long a, long long b, long long c) {
    long long l = 0, r = a + b + c;
    long long ans = 0;
    while (l <= r) {
        long long mid = l + ((r - l) >> 1);
        long long tol = 0;
        if (a >= mid) tol += mid;
        else tol += a + (mid - a) * 2;

        if (b >= mid) tol += mid;
        else tol += b + (mid - b) * 2;

        if (c >= mid) tol += mid;
        else tol += c + (mid - c) * 2;

        if (tol <= a + b + c) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    return ans;
}

long long main() {
    freopen("sougou_9_5/in_1.txt", "r", stdin);
    freopen("sougou_9_5/out_1.txt", "w", stdout);
    long long a, b, c;
    cin >> a >> b >> c;
    cout << fun(a, b, c) << endl;
    return 0;
}
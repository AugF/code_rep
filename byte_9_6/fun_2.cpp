#include <bits/stdc++.h>
using namespace std;


int main() { 
    // freopen("byte_9_6/in_1.txt", "r", stdin);
    // freopen("byte_9_6/out_1.txt", "w", stdout);    
    int n;
    cin >> n;
    
    vector<int> st(n), nums(n), left(n);

    int res = INT_MIN, tt = 0;
    for (int i = 0; i < n; i ++) {
        cin >> nums[i];
        while (tt && nums[st[tt]] <= nums[i]) tt --;
        if (tt) left[i] = st[tt] + 1;
        st[++ tt] = i;
    }

    tt = 0;
    for (int i = n - 1; i > 0; i --) {
        while (tt && nums[st[tt]] <= nums[i]) tt --;
        if (tt) {
            res = max(res, left[i] * (st[tt] + 1));
        }
        st[++ tt] = i;
    }
    cout << res << endl;
    return 0;
}
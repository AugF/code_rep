#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("netwase_pra/data/in_3.txt", "r", stdin);
    //freopen("netwase_pra/data/out_3.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i ++) cin >> nums[i];
    for (auto x: nums) {
        cout << n + 1 - x << ' ';
    }
    return 0;
}
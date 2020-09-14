#include <bits/stdc++.h>
using namespace std;

int ans;

void dfs(vector<int>& nums, int u, int x1, int x2) {
    if (u == nums.size()) return;
    if (x1 == x2) ans = max(ans, x1);
    
    dfs(nums, u + 1, x1 + nums[u], x2);
    dfs(nums, u + 1, x1, x2 + nums[u]);
    if (!ans) return; // 因为是全局
}

int main() {
    freopen("net_8_8/data/in_3.txt", "r", stdin);
    freopen("net_8_8/data/out_3.txt", "w", stdout);
    int T, n;
    vector<int> nums;
    cin >> T;
    while (T --) {
        nums.clear();
        cin >> n;
        nums.resize(n);

        int sum = 0;
        for (int i = 0; i < n; i ++) cin >> nums[i], sum += nums[i];

        ans = 0;
        dfs(nums, 0, 0, 0);
        cout << sum - ans * 2 << endl;
    }
    return 0;
}
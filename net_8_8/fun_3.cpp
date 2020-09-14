#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums, int x, int target) {
    vector<int> temp;
    for (int i = 0; i < nums.size(); i ++)
        if (!(x >> i & 1)) temp.push_back(nums[i]);

    int n = temp.size();
    for (int i = 0; i < 1 << n; i ++) {
        int tmp = 0;
        for (int j = 0; j < n; j ++)
            if (i >> j & 1) {
                tmp += temp[j];
                if (tmp > target) break;
            }
        if (tmp == target) return true;
    }
    return false;
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

        vector<pair<int, int>> temps;
        for (int i = 0; i < 1 << n; i ++) {
            int t = 0;
            for (int j = 0; j < n; j ++)
                if (i >> j & 1) t += nums[j];
            temps.push_back({t, i});
        } 

        sort(temps.begin(), temps.end());
        for (auto t: temps) {
            if (check(nums, t.second, (sum - t.first) / 2)) {
                cout << t.first << endl;
                break;
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n;

bool check(int u, vector<int>& nums) {
    if (u >= n) return true;
    
    int sum = nums[u] - 1;
    if (!sum) return true; // 空节点

    int s = u + 1;
    while (s < n) {
        sum -= nums[s];
        if (sum < 0) return false;
        if (!sum) break;
        s ++;
    }
    
    if (s == u + 1) return false;
    for (int i = u + 1; i <= s; i ++)
        if (!check(i, nums)) return false;
    return true;
}

int main() { 
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i ++) cin >> nums[i];
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        if (check(0, nums)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
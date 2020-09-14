#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("sougou_9_5/in_1.txt", "r", stdin);
    freopen("sougou_9_5/out_1.txt", "w", stdout);
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> nums{a, b, c};
    sort(nums.begin(), nums.end());
    int res = 0;
    res += nums[0];
    nums[1] -= nums[0], nums[2] -= nums[0];

    int r = nums[1] / 2;
    res += r;
    nums[1] -= 2 * r, nums[2] -= 2 * r;

    if (nums[1] == 1) {
        res += (nums[2] + 2) / 5;
    } else if (nums[1] == 0) res += nums[2] / 5;

    cout << res << endl;
    return 0;
}
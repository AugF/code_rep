#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m, nums[N];

int main() {
    //freopen("meituan_8_29/in_4.txt", "r", stdin);
    //freopen("meituan_8_29/out_4.txt", "w", stdout);
    
    cin >> m >> n;
    int min_v = INT_MAX, max_v = INT_MIN;
    for (int i = 0; i < n; i ++) cin >> nums[i], min_v = min(min_v, nums[i]), max_v = max(max_v, nums[i]);

    int ans = 0;
    // 寻找l和r的关系，然后二分l
    for (int l = 1; l <= m; l ++) 
        for (int r = l; r <= m; r ++) {
            bool flag = true;
            int pre_v = -1;
            for (int i = 0; i < n; i ++) {
                if ((nums[i] > 0 && nums[i] < l) || (nums[i] > r && nums[i] < m + 1)) {
                    if (nums[i] < pre_v) {
                        flag = false;
                        break;
                    } else pre_v = nums[i];
                } 
            }
            if (flag) {
                ans ++;
            }
        }

    cout << ans << endl;
    return 0;
}
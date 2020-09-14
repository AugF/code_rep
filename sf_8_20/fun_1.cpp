#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("sf_8_20/in_1.txt", "r", stdin);
    freopen("sf_8_20/out_1.txt", "w", stdout);
    int T;
    cin >> T;
    while (T --) {
        int n, m;
        cin >> n >> m;
        vector<int> nums(n);
        for (int i = 0; i < n; i ++) cin >> nums[i];
        sort(nums.begin(), nums.end());

        vector<vector<int>> vecs;
        for (int i = 0; i < m; i ++) {
            int x, y;
            cin >> x >> y;
            vecs.push_back({x, y});
        }

        // 按照钱降序，服务器升序
        sort(vecs.begin(), vecs.end(), [](vector<int>& a, vector<int>& b){
            if (a[1] != b[1]) return a[1] > b[1];
            return a[0] <= b[0];
        });

        int res = 0;
        for (int i = 0; i < vecs.size() && nums.size(); i ++) {
            int x = vecs[i][0], y = vecs[i][1];
            int l = 0, r = nums.size() - 1;
            while (l < r) {
                int mid = l + r >> 1;
                if (nums[mid] >= x) r = mid;
                else l = mid + 1;
            }
            if (nums[l] >= x) {
                res += y;
                nums.erase(nums.begin() + l);
            }
        }
        cout << res <<endl;
        cout << endl;
    }
    return 0;
}
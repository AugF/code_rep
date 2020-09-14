#include <bits/stdc++.h>
using namespace std;

/*
怪物
*/

int main() {
    int T;
    cin >> T;
    while (T --) {
        int n, m;
        vector<vector<int, int>> nums;
        for (int i = 0; i < n; i ++) {
            int a, b;
            cin >> a >> b;
            nums.push_back({a, b});
        }
        
        sort(nums.begin(), nums.end(), [](const vector<int, int>& a, const vector<int, int>& b){
            if (a[1] != b[1]) return a[1] > b[1];
            return a[0] < b[0];
        });

        // choose 1
        for (int i = 0; i < n; i ++) {
            if (nums[i][0] <= m) {
                
            }
        }
    }
    return 0;
}
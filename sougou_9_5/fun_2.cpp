#include <bits/stdc++.h>
using namespace std;

int fun(int t, int* xa, int xalen) {
    vector<pair<int, int>> nums;
    for (int i = 0; i < xalen; i += 2) {
        nums.push_back({*(xa + i), *(xa + i + 1) / 2.0});
    }

    sort(nums.begin(), nums.end());
    
    vector<double> lefts, rights;

    for (auto x: nums) {
        double a = x.first, len = x.second;
        lefts.push_back(a - len), rights.push_back(a + len);
    }
    
    int res = 2;
    for (int i = 0; i + 1 < lefts.size(); i ++) {
        double x = lefts[i + 1] - rights[i];
        if (x == t) res += 1;
        else if (x > t) res += 2;
    }
    return res;
}

int fun(int t, int* xa, int xaLen) {
    int count = 2;
    for (int i = 0; i< xaLen;) {
        double a = *(xa + i + 1) / 2.0, b = *(xa + i + 3) / 2.0; 
        if (*(xa + i + 2) - b - (*(xa + i) - a) > t) count += 2;
        else if (*(xa + i + 2) - b - (*(xa + i) - a) == t) count += 1;
        i += 2;
    }
    return count;
}


int main() {
    // freopen("sougou_9_5/in_1.txt", "r", stdin);
    freopen("sougou_9_5/out_1.txt", "w", stdout);
    int t = 2;
    int xa[] = {-1, 4, 5, 2}, xalen = 4;
    cout << fun(t, xa, xalen) << endl;
    return 0;
}
1. 给定二叉树的前序和中序遍历，求叶子节点的数目
节点个数不超过3e4
2. 最少去除几个字符可以使原字符串不包含某个字符串
输入：t（1<=t<=1000), 表示有t个样例; 每个样例一行字符串s，s的长度不大于1e5
输出：每个样例一行, 输出最少去掉字符串数

3. 某网站上有N个视频，每个视频时长为L_i秒。希望在其中插入M个广告；
要求: 一个视频里的两个广告必须间隔一段时间（可以为0），间隔时间是一个整数；
计算这个间隔时间最大可以设置为多少秒？如果不能插入M个广告，输出0
输入：第一行有两个整数N, M (1 <= N <= 1e5, N < M <= 5e6)；第二行有N个正整数，表示视频的时长(1 <= L_i <= 1e9)
输出：一个整数，表示最大的间隔时间
```
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
const int maxm = 5e6;
const int maxl = 1e9;

int video[maxn];

int main() {
 int n, m;
 cin >> n >> m;
 for (int i = 0; i < n; i++) {
  cin >> video[i];
 }
 long long cnt = 0;
 int l = 0, r = maxl;
 while (l < r) {
  int v = (l + r + 1) >> 1;
  cnt = 0;
  for (int i = 0; i < n; i++) {
            cnt++;
   cnt += video[i] / v;
   if (cnt >= m) break;
  }
  if (cnt >= m) l = v;
  else r = v - 1;
 }
 if (l == 0) cout << 0 << endl;
 else cout << l << endl;
}
```

4. 在n个正整数中，任意挑选k个（不可重复挑选，0<=k<=n）数字的和记为sum, 另外有一个正整数m，请问sum%m最大是多少？
输入：第一行两个正整数，分别为n和m；第二行为n个正整数
输出：一个数x，x表示sum % m的最大值
数据范围：2<=m<=1e9+7,  1<=n<=35
```
#include <bits/stdc++.h>
using namespace std;
const int maxn = 35;


int main() {
    int n, m;
    vector<int> nums(maxn);
    set<int> left, right;
    while (cin >> n >> m) {
        left.clear(); right.clear();
        for (int i = 0; i < n; i++) cin >> nums[i];
        int mid = (n - 1) / 2;
        for (int i = 0; i < (1 << (mid + 1)); i++) {
            int sum = 0;
            for (int j = 0; j <= mid; j++) {
                if ((i >> j) & 1) sum = (sum + nums[j]) % m;
            }
            left.insert(sum);
        }
        for (int i = 0; i < (1 << (n - mid - 1)); i++) {
            int sum = 0;
            for (int j = 0; j < n - mid - 1; j++) {
                if ((i >> j) & 1) sum = (sum + nums[j + mid + 1]) % m;
            }
            right.insert(sum);
        }
        int ans = 0;
        for (auto lit = left.begin(); lit != left.end(); lit++) {
            auto rit = right.lower_bound(m - *lit);
            if (rit != right.begin()) {
                --rit;
                ans = max(ans, *rit + *lit);
            } else {
                ans = max(ans, *lit);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```
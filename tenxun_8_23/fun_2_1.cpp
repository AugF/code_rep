// 字典序第k小的字符串： 寻找第k个有重复元素的全排列问题

#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("tenxun_8_23/in_2.txt", "r", stdin);
    freopen("tenxun_8_23/out_2.txt", "w", stdout);
    int T;
    cin >> T;
    while (T --) {
        string str;
        int n, k;
        cin >> str >> k;
        n = str.size();
        sort(str.begin(), str.end());

        string res;
        unordered_set<string> words;
        bool flag = true;
        for (int i = 0; i < n && flag; i ++) {
            for (int j = i; j < n; j ++) {
                string t = str.substr(i, j - i + 1);
                if (!words.count(t)) {
                    words.insert(t), --k;
                    if (!k) {
                        flag = false;
                        res = t;
                        break;
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}

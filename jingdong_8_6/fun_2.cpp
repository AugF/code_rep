#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];

void get_primes(int n) { // 线性筛素数
    cnt = 0;
    for (int i = 2; i <= n; i ++) {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++) {
            // 枚举小于n/i的质数
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

bool is_huiwen(int x) {
    string s1 = to_string(x), s2 = s1;
    reverse(s2.begin(), s2.end());
    return s1 == s2;
}

int main() {
    freopen("jingdong_8_6/data/in_2.txt", "r", stdin);
    freopen("jingdong_8_6/data/out_2.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    get_primes(m / 10);

    unordered_set<int> prime_sets;
    for (int i = 0; i < cnt; i ++) prime_sets.insert(primes[i]);

    int res = 0;
    for (int i = n; i <= m; i ++) {
        string s = to_string(i);
        int len_s = s.size();
        for (int j = 0; j < len_s; j ++) {
            int left = j? stoi(s.substr(0, j)): 0;
            int right = j == len_s - 1? 0: stoi(s.substr(j + 1));
            int x = left * pow(10, len_s - j - 1) + right;
            if (is_huiwen(x) && prime_sets.count(x)) {
                res ++;
                break;
            }
        }
    } 

    cout << res << endl;
    return 0;
}
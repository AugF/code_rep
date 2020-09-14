#include <iostream>
#include <cstdio>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cctype>
#include <stack>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <cmath>
//#include <bits/stdc++.h>
#define son1 (u << 2) - 2
#define son2 (u << 2) - 1
#define son3 (u << 2)
#define son4 (u << 2) | 1
using namespace std;
typedef long long lolo;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ulolo;

const int maxn = (int)1e6 + 5;
const int maxm = (int)2e6 + 5;
const int INF = 0x3f3f3f3f;
const lolo inf = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
const int MOD = 998244353;

template<class T>
inline void read(T &x) {
    x = 0; T flag = 1;char c;
    do { c = (char) getchar(); if (c == '-') break; } while (c < '0' || c > '9');
    if (c == '-') { c = '0', flag = -1;}
    do { x = x * 10 + c - '0';c = (char) getchar();} while (c >= '0' && c <= '9');
    x *= flag;
}
template<class T>
inline void out(T x) {
    if (x > 9) out(x / 10);
    x = x % 10;
    putchar('0' + x);
}

lolo a[105][1005], arr[105];
lolo maxsub(int n) {
    lolo ans = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (b > 0) {
            b += arr[i];
        } else {
            b = arr[i];
        }
        if (b > ans) {
            ans = b;
        }
    }
    return ans;
}
int main() {
    freopen("../in.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%lld", &a[i][j]);
        }
    }
    lolo ans = 0;
    for (int i = 0; i < m; ++i) {
        memset(arr, 0, sizeof(arr));
        for (int k = 0; k < m; ++k) {
            arr[k] += a[k][i];
        }
        ans = max(maxsub(m), ans);
        for (int j = i+1; j%m != i; ++j) {
            for (int k = 0; k < n; ++k) {
                arr[k] += a[k][j%m];
            }
            ans = max(maxsub(m), ans);
        }
    }
    printf("%lld\n", ans);
    return 0;
}
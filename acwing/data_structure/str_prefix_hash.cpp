/*
字符串hash：将字符串转化为数字
用处：求多次[l1, r1]和[l2, r2]的字符串是否相同

基本思想：将字符串看作p进制数（这里p为质数，经验值p=131,13331），然后对Q取模（Q=2^64).
假定人品好，不会处理

只需要记住123, 它的表示为1*p^2 + 2*p^1 + 3*p^0, 这里跟将字符串转换为十进制数是一样的效果
h[1..L], h[1..R]求h[L...R]
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10, P = 131;
typedef unsigned long long ULL;

int n, m;
ULL h[N], p[N]; // p存储的是进制, h存储的是实际的值
char str[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    cin >> n >> m >> str + 1;

    p[0] = 1;
    for (int i = 1; i <= n; i ++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }

    while (m --) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

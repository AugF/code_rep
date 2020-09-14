/*
hash表：把一个大的范围映射到一个小的范围

1. hash方式
h[x]: x mod 1e5
2. 处理冲突的方式
    - 拉链法: 如果冲突了，用链表进行扩充存储
    - 开放寻址法
        - 得到取模后的数, 如果当前不为空，并且当前不等于待插入的数，寻找下一个位置，如果找到了最后一个位置，则从开头找
            > 注意：这里如果位置满了，会陷入死循环
3. h[N], N这里取质数，指定0x3f3f3f3f为null

离散化是特殊的hash，需要保序
*/

// N次操作 200003, null = 0x3f3f3f3f
// hash: 取质数
// 拉链法
#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e5 + 3, null = 0x3f3f3f3f;

int h[N];

int find(int x) {
    int k = (x % N + N) % N; // 为了处理负数
    while (h[k] != null && h[k] != x) {
        k ++;
        if (k == N) k = 0;
    }
    return k;
}

int main() {
    int n;
    cin >> n;
    memset(h, 0x3f, sizeof h);
    
    while (n --) {
        string op;
        int x;
        cin >> op >> x;
        int k = find(x);
        if (op[0] == 'I') h[k] = x;
        else {
            if (h[k] != null) cout << "Yes" <<endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}

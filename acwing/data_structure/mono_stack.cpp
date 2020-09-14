/*
单调栈：主要用来解决求序列中某个数最近的最小值的问题

时间复杂度：O(n), 空间复杂度：O(n)

思想：当前元素插入后，因为当前元素是最小的数，所以后续的所有数要求最小数只会用到这个数，其前面大于的数不会用到，
此时可以将前面大于它的数弹出；此时栈中始终为单调

算法流程：
1. 如果当前栈顶元素比自己大，弹出；
2. 当前栈顶元素即为小于等于自己的元素
3. 将该元素插入栈中
*/

#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, st[N], tt;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int x;
        scanf("%d", &x);
        while (tt && st[tt] >= x) tt --;
        if (tt) cout << st[tt] << ' ';
        else cout << "-1" << ' ';
        st[++ tt] = x;
    }
    return 0;
}
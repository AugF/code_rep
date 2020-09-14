/*
求一段区间的最小值：单调队列，时间复杂度为O(n),空间复杂度为O(n)

算法步骤：
1. 判断队首元素是否滑出窗口
2. 若队尾的数大于当前数，则应该弹出（因为当前元素存在，队列中比它大的元素永远不会作为所需值）；当所有元素都弹出时，则可以插入
3. 此时，队首为当前的最小元素，即为所求

扩展：如果找一个值，用二分；如果找最值，单调队列
*/

#include <iostream>
using namespace std;
const int N = 1e6 + 10;

int n, k;
int a[N], q[N];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i ++) cin >> a[i];
    
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i ++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++;
        while (hh <= tt && a[q[tt]] >= a[i]) tt --;
        q[++ tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << ' ';
    }
    
    puts("");
    hh = 0, tt = -1;
    for (int i = 0; i < n; i ++) {
        if (hh <= tt && i - k + 1 > q[hh]) hh ++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt --;
        q[++ tt] = i;
        if (i >= k - 1) cout << a[q[hh]] << ' ';
    }
    return 0;
}
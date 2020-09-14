/*
堆排序: O(n) + O(klogk) 查找前k个最大值

堆是用一个静态数组维护一颗完全二叉树
1. 插入一个数 heap[++size]=x, up(size);
2. 求集合中的最小值 heap[1]
3. 删除最小值 heap[1] = heap[size]; size--; down(1);
4. 删除任意一个元素 heap[k] = heap[size]; size--; down(k); up(k);
5. 修改任意一个元素 heap[k] = x; down(x); up(x);

对于堆，左右儿子节点都是大于等于根节点。
根节点为x, 左儿子为2x, 右儿子为2x+1

基本操作：
down(x): 往下调整

建堆：
1. 将2/n-1的节点执行down操作；（完全二叉树一半的位置都为叶子节点）
节点*路径数 n/4 * 1 + n/8 * 2 + n/16 * 3; 错位相减法

取最小值, 即h[1]
删除最小值，将最后一个数放在1，down(1), size--
*/
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int h[N], cnt;

void down(int u) {
    int t = u; // 存储最小值
    if (2 * u <= cnt && h[t] > h[2 * u]) t = 2 * u;
    if (2 * u + 1 <= cnt && h[t] > h[2 * u + 1]) t = 2 * u + 1;
    if (t != u) {
        swap(h[t], h[u]);
        down(t);
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i ++) cin >> h[i];
    cnt = n;
    
    for (int i = n / 2; i; i --) down(i);
    
    while (m --) {
        printf("%d ", h[1]);
        h[1] = h[cnt --];
        down(1);
    }
    return 0;
}
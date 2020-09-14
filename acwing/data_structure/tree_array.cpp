/*
树状数组：
可以动态求前缀和（即给某个位置加上一个数，仍然能保证前缀和的正确性）
即单点修改+区间查询 O(logn)

区间修改+单点查询 O(logn)

树状数组每一层存储的数都是不一样的
第一层：存储最基本的值1, 3, 5, 7, 9, 11, 13, 15
第二层：2 C[2] = A[1] + A[2]
第三层：4 C[4] = A[1] + A[2] + A[3] + A[4]
...
每个数都是一段数的和
C[x]: x末尾有几个0就是第几层，利用了位运算
C[x]=(x-2^k, x], k是第k层，因此C[x]=(x-lowbit(x), x]

如何求前缀和：
res=C[x] + C[x-lowbit(x)] + C[x-lowbit(x)-lowbit(x)]..
for (int i = x; i >= 0; i -= lowbit(x)) res += C[i];

如何单点修改：a[x] += v
for (int i = x; i <= n; i += lowbit(x)) C[i] += v

最多logn位，所以时间复杂度为O(logn)

应用：
1. 数星星；因为是按照纵坐标递增的顺序给出的点，所以只需要判断横坐标有多少点？固定住一个点，即动态求前缀和
2. 楼兰图腾：这里有意思的一个事情是因为要只包含左边的数，所以需要动态，所以计算完后再求前缀和
3. 一个简单的整数问题：区间修改+单点查询, a[]->b[], 区间修改等于两个单点修改，单点查询等于求某个点的前缀和

特别地，如果范围不是1-n，可以通过离散化来做
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;

int n, m;
int a[N], tr[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), add(i, a[i]);
    
    while (m --) {
        int k, x, y;
        scanf("%d%d%d", &k, &x, &y);
        if (k == 0) printf("%d\n", query(y) - query(x - 1));
        else add(x, y);
    }
    return 0;
}
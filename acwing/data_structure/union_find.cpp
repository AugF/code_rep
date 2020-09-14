/*
并查集：
1. 将两个集合合并
2. 询问两个元素是否在集合中

近似O(1)的时间复杂度进行上面两个操作

基本原理：每个集合用一棵树来表示。树根的编号就是整个集合的编号。
每个节点存储它的父节点，p[x]表示x的父节点

1. 合并两个集合：将集合的根节点的父亲指向另一个集合的根节点
2. 询问两个集合是否在集合中：判断两个集合的根节点是否相同

如何寻找集合的根节点？
一直寻找p[x]的父亲，向上更新，直到p[x]=x; while (x != p[x]) x = p[x]; return x;
这里有一点优化，这里在寻找根节点的过程中会一并操作，将该路径上所有节点挂到根节点中

扩展：
1.并查集的find, 可以用unordered_map来做
2.如果要查找集合元素的个数，可以用cnt来维护。合并时更新，p[a]=b, cnt[b]+=cnt[a];

应用：
1. Kruskal算法
*/
#include <iostream>
using namespace std;
const int N = 1e5 + 10;

int n, m;
int p[N];

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) p[i] = i;
    
    while (m --) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M') {
            int pa = find(a), pb = find(b);
            if (pa != pb) p[pa] = pb;
        } else if (op == 'Q') {
            int pa = find(a), pb = find(b);
            cout << ((pa == pb) ? "Yes": "No") << endl;
        }
    }
    return 0;
}

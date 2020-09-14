/*
dfs: 
使用暴力搜索，题目奇怪，卡空间

思想：深入搜索然后进行恢复

理解：将dfs想象为一棵树去理解比较好，把所有路径都遍历一遍

常用剪枝策略:
1. 优化搜索顺序：大部分情况下，我们应该优先搜索分支较少的节点
2. 排除等效冗余：不考虑顺序的情况下，尽可能使用组合
3. 可行性剪枝：搜索到一半发现不合法，提前退出
4. 最优性剪枝：无论如何当前搜索到的结果都比最优取值差，剪枝
5. 记忆化搜索(DP) *

应用：
1. 排列数字：将1-n排成一排，问有多少种排列方法
思考：dfs
枚举每个位置上选择哪一个数，思考将一棵树转化为dfs代码

2. 八数码问题
每一行，每一列和每一
*/
#include <iostream>
using namespace std;
const int N = 10;

int path[N]; // 存储从根节点到叶节点搜索的路径
bool st[N]; // 每个数只能用一次
int n;

void dfs(int u) { // u这里即枚举顺序，
    if (u == n) { // 执行到根节点，进行恢复
        for (int i = 0; i < n; i ++) cout << path[i] << ' ';
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i ++)
        if (!st[i]) {
            st[i] = true; // 操作现场
            path[u] = i;
            dfs(u + 1); 
            st[i] = false; // 恢复现场
        }
}

int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}
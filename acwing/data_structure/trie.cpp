/*
Trie树：高效地存储和查找字符串 空间复杂度O(N),N为总节点数,时间复杂度O(M), M为最大字符串长度
> 一般来说，有多少个字符就开多大，字符数=数的最大长度*多少个数
本质为将字符串每个词看作一个节点，将相同前缀进行合并

数据结构：
son[M][26], 这里M也是Trie树的高度，26为每个节点的子树的个数
cnt[M]: 当前节点的数目
idx: 树中节点的编号，下标是0的点，即是根节点，又是空节点

插入：
1. 从p=0根节点开始
2. 对str中每个字符，如果根节点对应的该字符不存在，则创建新的节点，然后str移动到下一个位置, 并更新当前节点为父节点
3. str移动到最后一个位置，此时节点就表示该串，该串的计数加1

查询：
1. 从p=0根节点开始
2. 对str中每个字符，如果根节点对应的该字符不存在，说明字符不存在，返回false
3. str移动到最后一个位置，如果该节点计数不为0，返回true, 否则返回false

时间复杂度：O(M)
空间复杂度：深度为M的26叉树，总节点数为1 + 26^1 + ... + 26^M = (26^M - 1)/25. 因为这里m就是节点的编号

应用：
1. Trie字符串统计（统计一个字符串在集合中出现了多少次）
2. 最大异或对：对给定的N个整数中从中选择两个异或，得到的结果最大是多少？
    暴力：两重循环，枚举第一个数，然后枚举第二个数
    高位越大，结果越大，则30位到0；按上面的做法进行插入
    查询：如果当前非位存在，则结果加上1<<i，更新父节点;否则直接更新父节点; 最终返回结果

*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int son[N][26], cnt[N], idx;
char str[N];

void insert(char str[]) {
    int p = 0;
    for (int i = 0; i < strlen(str); i ++) {
        int x = str[i] - 'a';
        if (!son[p][x]) son[p][x] = ++ idx;
        p = son[p][x];
    }
    cnt[p] ++;
}

int query(char str[]) {
    int p = 0;
    for (int i = 0; i < strlen(str); i ++) {
        int x = str[i] - 'a';
        if (!son[p][x]) return 0;
        p = son[p][x];
    }
    return cnt[p] > 0? 1: 0;
}

int main() {
    idx = 0;
    int n;
    cin >> n;
    while (n --) {
        char op;
        cin >> op >> str;
        if (op == 'I') insert(str);
        else if (op == 'Q') cout << query(str) << endl;
    }
    return 0;
}
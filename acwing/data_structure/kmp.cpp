/*
kmp: 用于快速查找某个子串是否在字符串中
字符串匹配：
找模板串P在串S中出现的位置(是否存在)

S[N], P[M]
暴力做法：
for (int i = 1; i <= n; i ++) {
    bool flag = true;
    for (int j = 1; j <= m; j ++) {
        if (s[i] != p[j]) {
            flag = false;
            break;
        }
    }
}

KMP:
对P求next数组
ne[i] = j,p[1...j] = p[i-j+1, ...,i] 因为从1开始的，即匹配长度
j失配时，只需要重k的下一个位置开始匹配即可

匹配流程：(i=1, j=0, s和j都是从1开始编号的)
1. s的第i和p的第j+1个字符进行匹配，如果失配，j转向ne[j], 继续匹配S的第i个字符和p的第j+1个字符是否匹配，如果j为0，停止；或者已经匹配了
2. s[i] == p[j + 1], 则j++, 即p向下一个位置开始匹配
3. 如果j到达n（结束位置），说明匹配成功

举个例子：
s=""
p="abababab"
   12345678
   ne[1]=0, ne[2]=0, ne[3]=1
*/
#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;
char p[N], s[M];
int ne[N];

int main() {
    cin >> n >> p + 1 >> m >> s + 1;
    
    // 求ne数组, ne[1] = 0 此时求的过程也是一个完美的递归过程
    for (int i = 2, j = 0; i <= n; i ++) {
        while (j && p[i] != p[j + 1])  j = ne[j];
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }
    
    // kmp匹配过程
    for (int i = 1, j = 0; i <= m; i ++) {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++;
        if (j == n) {
            // 匹配成功
            printf("%d ", i - n); // 下标从1开始是i-n+1, 但是这里是从1开始
            j = ne[j];
        }
    }
    return 0;
}
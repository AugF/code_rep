/*
费解的开关：每个灯的状态会影响到它上下左右灯的状态，最少按几次才能使最终状态变为全1

首先，分析题：
每个开关按多次不如按1次，按的顺序无关

假设第一行的开关不能按了，问是否可以推出；
由第一行的开关推断出第二行开关，然后不断推出最后一行的状态
从而判断最后一行开关状态是否确定；如果最后一行状态全为1，则为合法问题

然后的想法就是枚举第一行开关可以操作的方案，从而来求出最小值

这里是递推的经典题
*/
#include <iostream>
#include <cstring>
using namespace std;

int n;
char g[6][6], f[6][6];
int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, -1, 0, 1, 0};

void turn(int x, int y) {
    for (int i = 0; i < 5; i ++) {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < 5 && b >= 0 && b < 5) {
            f[a][b] = (f[a][b] == '1')? '0': '1';
        }
    }
}

int main() {
    cin >> n;
    
    while (n --) {
        for (int i = 0; i < 5; i ++) cin >> g[i];
        
        int ans = 2e9;
        for (int i = 0; i < 1 << 5; i ++) {
            memcpy(f, g, sizeof g);
            int cnt = 0;
            // 0
            for (int j = 0; j < 5; j ++)
                if (i >> j & 1) {
                    turn(0, j);
                    cnt ++;
                }
            
            // 1-4
            for (int j = 1; j < 5; j ++) {
                for (int k = 0; k < 5; k ++)
                    if (f[j - 1][k] == '0') {
                        turn(j, k);
                        cnt ++;
                    }
            }
            
            bool success = true;
            // 4
            for (int j = 0; j < 5; j ++)
                if (f[4][j] == '0') {
                    success = false;
                    break;
                }
            if (success) ans = min(ans, cnt);
        }
        cout << (ans > 6? -1: ans) << endl;
    }
    return 0;
}

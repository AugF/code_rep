/*

*/
#include <bits/stdc++.h>
using namespace std;

const int V1 = 1010, V2 = 210;

int f[V1][V2], n, max_v1, max_v2;

int main() {
    freopen("huawei_8_5/data/in_3.txt", "r", stdin);
    freopen("huawei_8_5/data/out_3.txt", "w", stdout);    
    cin >> n >> max_v1 >> max_v2;

    while (n --) { // 可释放技能数，这里是多重背包问题
        int w, v1, v2;
        cin >> w >> v1 >> v2;
        for (int i = v1; i <= max_v1; i ++)
            for (int j = v2; j <= max_v2; j ++) 
                f[i][j] = max(f[i][j], f[i - v1][j - v2] + w), cout << f[i][j] << endl;
    }
    cout << f[max_v1][max_v2] << endl;
    return 0;
}
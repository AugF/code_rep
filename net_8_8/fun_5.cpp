#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("net_8_8/data/in_5.txt", "r", stdin);
    freopen("net_8_8/data/out_5.txt", "w", stdout);
    int x, y, z, a, b;
    cin >> x >> a >> y >> b >> z;

    y += a + b;
    if (y <= x || y <= z) { // 如果y是最小的
        cout << min(y, min(x, z)) << endl; 
        return 0;
    }

    // y > x, y > z; 将y填补到x, z小的中
    if (x > z) { // y填补到z
        int t = min(b, x - z);
        t = min(t, (y - z) / 2);  
        y -= t, b -= t, z += t;
    } else if (z > x) { // 将y填补到x
        int t = min(a, z - x); 
        t = min(t, (y - z) / 2);  
        y -= t, a -= t, x += t; 
    }

    if (y <= x || y <= z || !a || !b) { // 移动后，y不是最高的或者a,b已经没有了，此时为最终状态
        cout << min(y, min(x, z)) << endl;
        return 0;
    }

    // y仍然大于x和z, 此时x=z, 同时将y移动到x,z;
    int t = min(a, b);
    t = min(t, (y - x) / 3); // y最多降低到与x,z相等的距离;  y-2t >= x+t; 
    y -= 2 * t, x += t, z += t; // 移动
    cout << min(x, z) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("huawei_8_12/data/in_1.txt", "r", stdin);
    // freopen("huawei_8_12/data/out_1.txt", "w", stdout);
    int p5 = 0, p10 = 0;
    string str;
    cin >> str;

    int len = str.size(), correct = 0, cnt = 0, i = 0;   
    while (i < len) {
        if (str[i] == ',') {
            i ++;
            continue;
        }
        int x = 0;
        while (i < len && isdigit(str[i])) x = x * 10 + str[i] - '0', i ++;
        cnt ++;
        if (x == 5) p5 ++;
        else if (x == 10) {
            if (p5 < 1) break;
            p5 --, p10 ++;
        } else if (x == 20) {
            if (p10 > 1 && p5 > 1) p10 --, p5 --;
            else if (p5 > 3) p5 -= 3;
            else break;
        }
        correct ++;
    }

    if (cnt == correct) cout << "true, " << cnt << endl;
    else cout << "false, " << cnt << endl;
    return 0;
}
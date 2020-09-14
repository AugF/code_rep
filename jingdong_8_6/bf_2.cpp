#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 10;

int main() {
    freopen("jingdong_8_6/data/answer_2.txt", "w", stdout);
    int cnt = 0;
    for (int i = 2; i <= MAX_N; i ++) {
        bool flag = true;
        for (int j = 2; j < i / j; j ++)
            if (i % j == 0) {
                flag = false;
                break;
            }
        if (flag) {
            string t1 = to_string(i), t2 = t1;
            reverse(t2.begin(), t2.end());
            if (t1 == t2) printf("%d, ", i); 
        }
    }
    return 0;
}
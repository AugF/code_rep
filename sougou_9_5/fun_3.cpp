#include <bits/stdc++.h>
using namespace std;

int birth_trials_needed_to_get_boy_and_girl() {
    int cnt = 1e6, N = 999;
    int boys = 0, girls = 0;
    srand((unsigned)time(NULL));
    for (int i = 0; i < cnt; i ++) {
        double x = rand() % (N + 1) / (double) (N + 1);
        if (x >= 0.5) boys ++;
        else girls ++;
        if (boys >= 1 && girls >= 1) {
            cout << boys << ' ' << girls << endl;
            cout << i << endl;
            return i;
        }
    }
    return -1; // 1e6次失败
}

int main() {
    birth_trials_needed_to_get_boy_and_girl();
    return 0;
}
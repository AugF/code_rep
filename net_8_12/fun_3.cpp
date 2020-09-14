/*
第3题：
思路：用栈来维护, 子事件一定比父事件先结束

1. 如果是开始标志，入栈；如果是结束标志，出栈，收集事件, 栈顶元素置标志，减去当前的时间;
2. 维护全局变量，如果时间相等，输出id最小的;
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("net_8_12/data/in_3.txt", "r", stdin);
    freopen("net_8_12/data/out_3.txt", "w", stdout);
    int T;
    cin >> T;
    while (T --) {
        int n;
        cin >> n;
        
        long long max_time = INT_MIN;
        int max_id = 0;
        stack<pair<int, long long>> stk;
        while (n --) {
            int time, id, s;
            cin >> time >> id >> s;
            if (s == 0) stk.push({id, time});
            else if (s == 1) {
                auto t = stk.top();
                stk.pop();
                long long use_time = time - t.second; // 当前时间段所花的时间
                if (stk.size()) stk.top().second += use_time; // 算其父时间段时，减去子时间段
                if (use_time > max_time) max_time = use_time, max_id = id; // 更新最耗时的时间段
                else if (use_time == max_time) max_id = min(id, max_id); // 保留最小的id
            }
        }
        cout << max_id << endl;
    }
}
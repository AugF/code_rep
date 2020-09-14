/*
计算器模拟：
算法思路为
1. 最初符号为+
2. 如果遇到
*/
#include <bits/stdc++.h>
using namespace std;

int calculate(string &s, size_t &pos) {
    stack<int> nums;
    int v = 0;
    char ch = '+'; // ch存储的是之前的运算符
    while (pos < s.size()) {
        if (isdigit(s[pos])) v = v * 10 + (s[pos] - '0');
        if ((!isdigit(s[pos]) && s[pos] != ' ') || pos == s.size() - 1) {
            if (s[pos] == '(' || s[pos] == '[' || s[pos] == '{') v = calculate(s, ++pos);
            if (ch == '+') nums.push(v);
            else if (ch == '-') nums.push(-v);
            else {
                int num = nums.top(); nums.pop();
                if (ch == '*') nums.push(num * v);
                else if (ch == '/') nums.push(num / v);
            }
            ch = s[pos];
            v = 0;
        }
        pos++;
        if (s[pos - 1] == ')' || s[pos - 1] == ']' || s[pos - 1] == '}') break;
    }
    int ans = 0;
    while (!nums.empty()) {
        ans += nums.top();
        nums.pop();
    }
    while (pos < s.size() && s[pos] == ' ') pos++;
    return ans;
}

int main() {
    string s;
    while (cin >> s) {
        size_t pos = 0;
        cout << calculate(s, pos) << endl;
    }
    return 0;
}
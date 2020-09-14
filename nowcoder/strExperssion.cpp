#include <bits/stdc++.h>
using namespace std;

int get_cal(int a, int b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    return a / b;
}

int main() {
    string str;
    cin >> str;
    stack<int> nums, ops;
    
    unordered_map<char, char> priority = {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}};
    unordered_map<char, char> symbols = {{']', '['}, {')', '('}, {'}', '{'}};
    for (int i = 0; i < str.size(); i ++) {
        if (isdigit(str[i])) {
            int j = i, tmp = 0;
            while (j < str.size() && isdigit(str[j])) tmp = tmp * 10 - '0' + str[j ++]; 
            i = j - 1;
            nums.push(tmp);
        } else if (priority.count(str[i])) {
            while (ops.size() && priority.count(ops.top()) && priority[ops.top()] >= priority[str[i]]) {
                int t = nums.top();
                char op = ops.top();
                nums.pop(), ops.pop();
                nums.top() = get_cal(nums.top(), t, op);
            }
            ops.push(str[i]);
        } else if (symbols.count(str[i])) {
            while (ops.size() && ops.top() != symbols[str[i]]) {
                int t = nums.top();
                char op = ops.top();
                nums.pop(), ops.pop();
                nums.top() = get_cal(nums.top(), t, op);
            }
            ops.pop();
        } else ops.push(str[i]);
    }
    
    while (ops.size()) {
        int t = nums.top();
        char op = ops.top();
        nums.pop(), ops.pop();
        nums.top() = get_cal(nums.top(), t, op);
    }
    cout << nums.top() << endl;
    return 0;
}
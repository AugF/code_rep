#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr) {}
};

void inorder_recursive(TreeNode *root) {
    stack<TreeNode*> stk;
    
    vector<int> res;
    TreeNode *p = root;
    while (stk.size() || p) {
        while (p) {
            stk.push(p);
            p = p->left;
        }
        if (stk.size()) {
            p = stk.top();
            stk.pop();
            res.push_back(p->val);
            p = p->right;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    // 完全二叉树
    for (int i = 0; i < n; i ++) cin >> nums[i];
    return 0;
}
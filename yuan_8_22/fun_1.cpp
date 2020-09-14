#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left; 
    TreeNode* right;
    TreeNode(int val):val(val), left(nullptr), right(nullptr){}
};

void preorder_tree(TreeNode* root, vector<int>& ans) {
    if (!root) return;
    if (!root->left && !root->right) ans.push_back(root->val); // 收集叶子节点
    preorder_tree(root->left, ans);
    preorder_tree(root->right, ans);
}

int main() {
    /*freopen("yuan_8_22/in_1.txt", "r", stdin);
    freopen("yuan_8_22/out_1.txt", "w", stdout);

    int T;
    cin >> T;
    while (T --) {*/
        int n;
        cin >> n;
        vector<int> nodes(n);
        for (int i = 0; i < n; i ++) cin >> nodes[i];

        // build tree
        TreeNode* root = new TreeNode(nodes[0]);
        TreeNode* p = root;
        int k = 0;
        queue<TreeNode*> q;
        q.push(p);

        vector<int> lefts, rights;
        lefts.push_back(root->val); // 加入root节点
        
        bool flag = true;
        while (flag && k < n - 1) {
            int s = q.size();
            
            for (int i = 0; i < s; i ++) {
                auto t = q.front();
                q.pop();

                // left
                t->left = new TreeNode(nodes[++k]);
                q.push(t->left);
                if (i == 0) lefts.push_back(t->left->val);
                if (k == n - 1) {
                    flag = false;
                    break;
                }

                // right
                t->right = new TreeNode(nodes[++k]);
                q.push(t->right);
                if (i == s - 1) rights.push_back(t->right->val);
                if (k == n - 1) {
                    flag = false;
                    break;
                }
            }
        }

        vector<int> leafs;
        preorder_tree(root, leafs);

        // 输出
        for (auto x: lefts) cout << x << ' ';
        for (int i = 1; i < leafs.size() - 1; i ++) cout << leafs[i] << ' ';
        for (int i = rights.size() - 1; i >= 0; i --) cout << rights[i] << ' ';
        cout << endl;
    //}
    // system("pause");
    return 0;
}
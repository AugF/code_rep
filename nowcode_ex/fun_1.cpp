#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val):val(val),left(nullptr),right(nullptr){}
};

TreeNode* stringToTreeNode(string str) {
    int i = 0, j = str.size() - 1;
    while (i < j && str[i] == ' ') i ++;
    while (i < j && str[i] == ' ') j --;
    str = str.substr(i, j - i + 1);
    if (str.empty()) return nullptr;

    string item;
    stringstream ss;
    ss.str(str);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> q;
    q.push(root);

    while (true) {
        auto t = q.front();
        q.pop();

        if (!getline(ss, item, ',')) break;
        if (item != "null") {
            int left = stoi(item);
            t->left = new TreeNode(left);
            q.push(t->left);
        }

        if (!getline(ss, item, ',')) break;
        if (item != "null") {
            int right = stoi(item);
            t->right = new TreeNode(right);
            q.push(t->right);
        }
    }
    return root;
}

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

int main() {
    string str;
    cin >> str; // [1,2,3,4,5,null]

    // build tree
    TreeNode *root = stringToTreeNode(str);
    prettyPrintTree(root);
    system("pause");
    return 0;
}
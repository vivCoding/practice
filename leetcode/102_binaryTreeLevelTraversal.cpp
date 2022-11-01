#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == NULL) return res;
    queue<TreeNode*> q;
    vector<int> curr;
    q.push(root);
    int ct = 1;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        curr.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
        ct--;
        if (ct == 0) {
            res.push_back(curr);
            curr.clear();
            ct = q.size();
        }
    }
    return res;
}
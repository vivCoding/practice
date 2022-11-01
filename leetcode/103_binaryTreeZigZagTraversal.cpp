#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == NULL) return res;
    deque<TreeNode*> q;
    int ct = 1;
    bool toRight = true;
    q.push_back(root);
    vector<int> curr;
    while (!q.empty()) {
        TreeNode* node;
        if (toRight) {
            node = q.back();
            q.pop_back();
        } else {
            node = q.front();
            q.pop_front();
        }
        curr.push_back(node->val);
        if (toRight) {
            if (node->left) q.push_front(node->left);
            if (node->right) q.push_front(node->right);
        } else {
            if (node->right) q.push_back(node->right);
            if (node->left) q.push_back(node->left);
        }
        ct--;
        if (ct == 0) {
            res.push_back(curr);
            curr.clear();
            ct = q.size();
            toRight = !toRight;
        }
    }
    return res;
}
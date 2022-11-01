#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/container-with-most-water/
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
    deque<TreeNode*> q;
    int ct = 1;
    bool alt = true;
    q.push_back(root);
    vector<int> curr;
    while (!q.empty()) {
        TreeNode* node = alt ? q.front();
        q.pop();
        if (node != NULL) {
            curr.push_back(node->val);
            if (alt) {
                q.push(node->right);
                q.push(node->left);
            } else {
                q.push(node->left);
                q.push(node->right);
            }
        }
        ct--;
        if (ct == 0) {
            res.push_back(curr);
            curr.clear();
            ct = q.size();
            alt = !alt;
        }
    }
    if (!curr.empty()) {
        res.push_back(curr);
    }
    return res;
}
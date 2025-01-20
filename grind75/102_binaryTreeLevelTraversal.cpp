#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/description/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        vector<int> curr;
        queue<TreeNode*> q;
        q.push(root);
        int ct = 1;
        while (!q.empty()) {
            auto next = q.front();
            q.pop();
            curr.push_back(next->val);
            if (next->left) q.push(next->left);
            if (next->right) q.push(next->right);
            ct--;
            if (ct == 0) {
                ct = q.size();
                res.push_back(curr);
                curr.clear();
            }
        }
        return res;
    }
};
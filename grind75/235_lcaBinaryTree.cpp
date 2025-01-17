#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    // take advantage that it's a BST
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto res = dfs(root, p, q);
        return res.first;
    }

    pair<TreeNode*, pair<bool, bool>> dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool pFound = false;
        bool qFound = false;
        if (root->val == p->val) pFound = true;
        if (root->val == q->val) qFound = true;
        if (root->left) {
            auto res = dfs(root->left, p, q);
            if (res.second.first && res.second.second) return res;
            if (res.second.first) pFound = true;
            if (res.second.second) qFound = true;
        }
        if (root->right) {
            auto res = dfs(root->right, p, q);
            if (res.second.first && res.second.second) return res;
            if (res.second.first) pFound = true;
            if (res.second.second) qFound = true;
        }
        return {root, {pFound, qFound}};
    }
};
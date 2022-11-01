#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/validate-binary-search-tree/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode* node, long long mn, long long mx) {
    if (node == NULL) return true;
    if (mn >= node->val || node->val >= mx) {
        return false;
    }
    return dfs(node->left, mn, node->val) && dfs(node->right, node->val, mx);
}

bool isValidBST(TreeNode* root) {
    return dfs(root, LONG_LONG_MIN, LONG_LONG_MAX);
}
#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode* node, int ct, int mx, bool isLeft) {
    if (node == NULL) return max(ct - 1, mx);
    cout << node->val << ", " << ct << ", " << mx << endl;
    if (isLeft) {
        mx = max(mx, dfs(node->right, ct + 1, mx, false));
        mx = max(mx, dfs(node->left, 1, mx, true));
    } else {
        mx = max(mx, dfs(node->left, ct + 1, mx, true));
        mx = max(mx, dfs(node->right, 1, mx, false));
    }
    return mx;
}

int longestZigZag(TreeNode* root) {
    return max(dfs(root->left, 1, 0, true), dfs(root->right, 1, 0, false));
}
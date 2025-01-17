#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/balanced-binary-tree/
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
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        if (leftHeight == -1 || rightHeight == -1) return -1;
        int height = max(leftHeight, rightHeight) + 1;
        if (abs(leftHeight - rightHeight) > 1) return -1;
        return height;
    }
};
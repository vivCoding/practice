#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
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
    int kthSmallest(TreeNode* root, int k) {
        return dfs(root, k);
    }

    int ct = 0;
    int dfs(TreeNode* node, int k) {
        // means nothing happens
        if (node == NULL) return -1;
        // in-order traversal
        int res = dfs(node->left, k);
        if (res != -1) return res;
        ct++;
        if (ct == k) return node->val;
        return dfs(node->right, k);
    }
};
#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/add-binary/
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
    int maxCt = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root, 0);
        return maxCt;
    }

    int dfs(TreeNode* node, int currCt) {
        if (node == NULL) return currCt;
        int lct = dfs(node->left, currCt);
        int rct = dfs(node->right, currCt);
        maxCt = max(maxCt, lct + rct + 1);
        currCt = max(lct, rct) + 1;
        return currCt;
    }
};
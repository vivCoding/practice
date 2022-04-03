#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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
    int maxDiameter = 0;

    int rec(TreeNode* root) {
        if (!root->left && !root->right) {
            return 1;
        }
        int leftChildCount = root->left ? rec(root->left) : 0;
        int rightChildCount = root->right ? rec(root->right) : 0;
        maxDiameter = max(leftChildCount + rightChildCount, maxDiameter);
        return max(leftChildCount, rightChildCount) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        rec(root);
        return maxDiameter;
    }
};
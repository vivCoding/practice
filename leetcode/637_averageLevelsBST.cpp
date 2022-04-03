#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://leetcode.com/problems/average-of-levels-in-binary-tree/
 */

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
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    struct NodeLevel {
        TreeNode* node;
        int level;
    };
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<NodeLevel> q;
        q.push({ root, 1 });
        while (!q.empty()) {
            struct NodeLevel nl = q.front();
            q.pop();
            if (nl.node->left) q.push({ nl.node->left, nl.level + 1 });
            if (nl.node->right) q.push({ nl.node->right, nl.level + 1 });
            double count = 1, sum = nl.node->val;
            while (q.front().level == nl.level && !q.empty()) {
                NodeLevel n2 = q.front();
                q.pop();
                if (n2.node->left) q.push({ n2.node->left, n2.level + 1 });
                if (n2.node->right) q.push({ n2.node->right, n2.level + 1 });
                sum += n2.node->val;
                count++;
            }
            res.push_back(sum / count);
        }
        return res;
    }
};

#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/clone-graph/description/
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        Node* res = new Node(node->val);
        unordered_map<int, Node*> visited;
        dfs(node, res, &visited);
        return res;
    }

    void dfs(Node* node, Node* clone, unordered_map<int, Node*>* visited) {
        visited->insert({node->val, clone});
        for (auto neighbor : node->neighbors) {
            if (visited->find(neighbor->val) == visited->end()) {
                Node* neighborClone = new Node(neighbor->val);
                clone->neighbors.push_back(neighborClone);
                dfs(neighbor, neighborClone, visited);
            } else {
                clone->neighbors.push_back(visited->find(neighbor->val)->second);
            }
        }
    }
};
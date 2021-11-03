#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://cses.fi/problemset/task/1131
 * UNSOLVED
*/

int diameter = 0;

int count_nodes(int ni, int parent, vector<pair<int, int>> tree[]) {
    int maxCount = 0;
    for (pair<int, int> node : tree[ni]) {
        if (node.first != parent && node.second == -1) {
            node.second = count_nodes(node.first, ni, tree) + 1;
        }
        if (node.second > maxCount) {
            maxCount = node.second;
        }
    }
    return maxCount;
}

int main() {
    int n; cin >> n;
    vector<pair<int, int>> tree[n];
    for (int i = 0; i < n - 1; i++) {
        int t, t2;
        cin >> t >> t2;
        tree[t - 1].push_back(pair<int, int>(t2 - 1, -1));
        tree[t2 - 1].push_back(pair<int, int>(t - 1, -1));
    }
    int diameter = -1;
    for (int i = 0; i < n; i++) {
        int maxCount = count_nodes(i, -1, tree);
        if (maxCount > diameter) {
            diameter = maxCount;
        }
    }
    cout << diameter << endl;
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://cses.fi/problemset/task/1131
 * UNSOLVED
*/

int dfs(int ni, int parent, vector<int> tree[], int count) {
    int maxCount = count;
    for (int child : tree[ni]) {
        if (child != parent) {
            int childCount = dfs(child, ni, tree, count + 1);
            if (childCount > maxCount) {
                maxCount = childCount;
            }
        }
    }
    return maxCount;
}

int main() {
    int n; cin >> n;
    vector<int> tree[n];
    for (int i = 0; i < n - 1; i++) {
        int t, t2;
        cin >> t >> t2;
        tree[t - 1].push_back(t2 - 1);
        tree[t2 - 1].push_back(t - 1);
    }

    if (tree[0].size() > 1) {
        vector<int> cd;
        for (int child : tree[0]) {
            cd.push_back(dfs(child, 0, tree, 1));
        }
        sort(cd.begin(), cd.end());
        cout << *(cd.end() - 1) + *(cd.end() - 2) << endl;
    } else {
        cout << dfs(0, -1, tree, 0) << endl;
    }

    return 0;
}
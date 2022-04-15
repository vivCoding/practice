#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://cses.fi/problemset/task/1131
*/

int maxDiameter = 0;

int dfs (int ni, int parent, vector<int>* tree) {
    int mc1 = 0, mc2 = 0;
    int maxChildCount = 0;
    for (int child : tree[ni]) {
        if (child != parent) {
            int childCount = dfs(child, ni, tree);
            maxChildCount = max(childCount, maxChildCount);
            if (childCount > mc1) {
                if (childCount > mc2) {
                    mc1 = mc2;
                    mc2 = childCount;
                } else {
                    mc1 = childCount;
                }
            }
        }
    }
    maxDiameter = max(mc1 + mc2, maxDiameter);
    return maxChildCount + 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> tree[n];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a - 1].push_back(b - 1);
        tree[b - 1].push_back(a - 1);
    }
    dfs(0, 0, tree);
    cout << maxDiameter << endl;
    return 0;
}
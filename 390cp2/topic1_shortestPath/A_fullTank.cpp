#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/knssyb/problems/fulltank
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int prices[n];
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    unordered_map<int, int> roads[n] = {};
    int u, v, d;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> d;
        roads[u][v] = d;
    }
    int q; cin >> q;
    int c, s, e;
    for (int t = 0; t < q; t++) {
        cin >> c >> s >> e;
        
    }
    return 0;
}
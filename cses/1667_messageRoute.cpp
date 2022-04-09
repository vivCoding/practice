#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1667
*/


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vector<vll> g;
    g.reserve(n);
    ll visited[n] = {};
    ll t1, t2;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        g[t1 - 1].push_back(t2 - 1);
        g[t2 - 1].push_back(t1 - 1);
    }
    visited[0] = 1;
    queue<ll> q;
    ll parent[n];
    parent[0] = 0;
    q.push(0);
    while (!q.empty()) {
        ll next = q.front();
        q.pop();
        if (next == n - 1) {
            vll path;
            for (ll i = next; i != 0; i = parent[i]) {
                path.push_back(i);
            }
            path.push_back(0);
            cout << path.size() << endl;
            for (auto p = path.rbegin(); p != path.rend(); p++) {
                cout << *p + 1 << " ";
            }
            cout << endl;
            return 0;
        }
        for (ll child : g[next]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = 1;
                parent[child] = next;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
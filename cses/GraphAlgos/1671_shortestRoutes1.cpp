#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1671
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vector<vector<pll>> g;
    g.reserve(n);
    ll ds[n];
    bool visited[n] = {};
    ll t1, t2, t3;
    priority_queue<pll> q;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3;
        g[t1 - 1].push_back({ t2 - 1, t3 });
        ds[t1 - 1] = INT_MAX;
    }
    ds[0] = 0;
    q.push({ 0, 0 });
    while (!q.empty()) {
        ll next = q.top().second;
        q.pop();
        if (!visited[next]) {
            visited[next] = true;
            for (pll p : g[next]) {
                ll child = p.first, length = p.second;
                if (ds[next] + length < ds[child]) {
                    ds[child] = ds[next] + length;
                    q.push({ -ds[child], child });
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ds[i] << " ";
    }
    cout << endl;
    return 0;
}
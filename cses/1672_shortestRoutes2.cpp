#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1672
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m, q; cin >> n >> m >> q;
    vector<pll> g[n];
    ll queries[q];
    ll a, b, c;
    ll ds[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ds[i][j] = i == j ? 0 : INT64_MAX / 2;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({ b, c });
        g[b].push_back({ a, b });
        ds[a][b] = min(ds[a][b], c);
        ds[b][a] = min(ds[a][b], c);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ds[i][j] = min(ds[i][j], ds[i][k] + ds[k][j]);
            }
        }
    }
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        a--, b--;
        cout << (ds[a][b] == INT64_MAX / 2 ? -1 : ds[a][b]) << endl;
    }
    return 0;
}
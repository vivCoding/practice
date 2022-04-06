#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1619
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    vector<pll> pts;
    ll a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        pts.push_back({ a, 1 });
        pts.push_back({ b, -1 });
    }
    sort(pts.begin(), pts.end());
    ll ct = 0;
    ll maxCt = -1;
    for (pll pt : pts) {
        ct += pt.second;
        maxCt = max(ct, maxCt);
    }
    cout << maxCt << endl;
    return 0;
}
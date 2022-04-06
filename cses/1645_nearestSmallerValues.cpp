#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1645
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    stack<pll> s;
    ll temp;
    for (ll i = 0; i < n; i++) {
        cin >> temp;
        while (!s.empty() && s.top().first >= temp) {
            s.pop();
        }
        if (s.empty()) {
            cout << "0 ";
        } else {
            cout << s.top().second + 1 << " ";
        }
        s.push({ temp, i });
    }
    return 0;
}
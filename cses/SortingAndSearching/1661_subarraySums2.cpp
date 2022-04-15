#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1661
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x; cin >> n >> x;
    ll ct = 0;
    ll temp;
    ll ps = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        ps += temp;
        ct += mp[ps - x];
        mp[ps]++;
    }
    cout << ct << endl;
    return 0;
}
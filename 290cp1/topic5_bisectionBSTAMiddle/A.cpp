#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://purdue.kattis.com/sessions/oy5cet/problems/financialplanning
 */

bool comp(pll a, pll b) {
    double ra = (double) a.first / (a.second);
    double rb = (double) b.first / b.second;
    return ra > rb;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    vector<pll> ivs;
    ll temp1, temp2;
    for (int i = 0; i < n; i++) {
        cin >> temp1 >> temp2;
        ivs.push_back({ temp1, temp2 });
    }
    sort(ivs.begin(), ivs.end(), comp);
    ll l = 0, r = 2e9 + 1;
    ll mid;
    while (l < r) {
        mid = l + (r - l) / 2;
        ll sum = 0;
        bool found = false;
        for (auto iv : ivs) {
            sum += iv.first * mid - iv.second;
            if (sum >= m) found = true;
        }
        if (found) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
    return 0;
}
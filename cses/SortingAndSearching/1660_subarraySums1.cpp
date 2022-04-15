#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1660
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x; cin >> n >> x;
    ll nums[n];
    for (ll i = 0; i < n; i++) {
        cin >> nums[i];
    }
    ll i = 0, j = 0;
    ll ct = 0;
    ll sum = nums[i];
    while (true) {
        if (sum == x) ct++;
        if (i == j) {
            if (j == n - 1) break;
            else {
                sum += nums[++j];
                continue;
            }
        }
        if (sum <= x) {
            if (j == n - 1) break;
            else {
                sum += nums[++j];
            }
        } else {
            sum -= nums[i++];
        }
    }
    cout << ct << endl;
    return 0;
}
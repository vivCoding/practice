#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1636
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x; cin >> n >> x;
    ll nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vll dp(x + 1);
    dp[0] = 1;
    for (ll num : nums) {
        for (int i = 1; i <= x; i++) {
            if (i - num >= 0) {
                dp[i] += dp[i - num];
                dp[i] = dp[i] % MOD9;
            }
        }
    }
    cout << dp[x] % MOD9 << endl;
    return 0;
}
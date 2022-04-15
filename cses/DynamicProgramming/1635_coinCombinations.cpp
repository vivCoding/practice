#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://cses.fi/problemset/task/1635
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    int nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int dp[x + 1];
    dp[0] = 0;
    for (int i = 1; i < x + 1; i++) {
        dp[i] = 0;
        for (int num : nums) {
            if (num == i) {
                dp[i]++;
            }
            if (i - num >= 0) {
                dp[i] += dp[i - num] % MOD9;
            }
        }
    }
    cout << dp[x] % MOD9 << endl;
    return 0;
}
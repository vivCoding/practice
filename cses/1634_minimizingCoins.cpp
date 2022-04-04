#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://cses.fi/problemset/task/1634
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
        dp[i] = INT_MAX;
        for (int num : nums) {
            if (i - num >= 0) {
                dp[i] = min(dp[i], dp[i - num] + 1);
            }
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;
    return 0;
}
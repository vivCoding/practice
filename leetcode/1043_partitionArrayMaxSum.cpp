#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/partition-array-for-maximum-sum/
 */

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i < n + 1; i++) {
            dp[i] = dp[i - 1] + arr[i - 1];
            int m = arr[i - 1];
            for (int j = i - 1; j >= max(0, i - k); j--) {
                m = max(arr[j], m);
                dp[i] = max(m * (i - j) + dp[j], dp[i]);
            }
        }
        return dp[n];
    }
};
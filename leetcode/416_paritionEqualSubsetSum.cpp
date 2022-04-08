#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/partition-equal-subset-sum/
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 0-1 knapsack problem
        // dp(x, k) = can we achieve sum x with first k elements?
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) {
            return false;
        }
        int x = sum / 2, k = nums.size();
        bool dp[x + 1][k + 1];
        for (int i = 0; i <= x; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for (int ki = 1; ki <= nums.size(); ki++) {
            for (int xi = 0; xi <= x; xi++) {
                dp[xi][ki] = dp[xi][ki - 1];
                if (xi - nums[ki - 1] >= 0) {
                    dp[xi][ki] |= dp[xi - nums[ki - 1]][ki - 1];
                }
            }
        }
        return dp[x][k];
    }
};
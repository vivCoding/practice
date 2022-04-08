#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/minimum-path-sum/
 */

class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {
        ll m = grid.size(), n = grid[0].size();
        ll dp[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    dp[i][j] = min(i > 0 ? dp[i - 1][j] : INT_MAX, j > 0 ? dp[i][j - 1] : INT_MAX) + grid[i][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
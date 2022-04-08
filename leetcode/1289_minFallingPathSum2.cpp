#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/minimum-falling-path-sum-ii/
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        ll n = grid.size();
        ll dp[n][n];
        pll m1 = { INT_MAX, -1 }, m2 = { INT_MAX, -1 };
        for (int i = 0; i < n; i++) {
            pll nm1 = {INT_MAX, -1}, nm2 = {INT_MAX, -1};
            for (int j = 0; j < n; j++) {
                if (i == 0) {
                    dp[i][j] = grid[i][j];
                } else {
                    if (m1.second != j) {
                        dp[i][j] = m1.first + grid[i][j];
                    } else {
                        dp[i][j] = m2.first + grid[i][j];
                    }
                }
                if (dp[i][j] < nm2.first) {
                    if (dp[i][j] < nm1.first) {
                        nm2 = nm1;
                        nm1 = { dp[i][j], j };
                    } else {
                        nm2 = { dp[i][j], j };
                    }
                }
            }
            m1 = nm1;
            m2 = nm2;
        }
        return m1.first;
    }
};
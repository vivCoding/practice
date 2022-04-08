#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/coin-change-2/
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vll dp(amount + 1);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = 1; i <= amount; i++) {
                if (i - coin >= 0) {
                    dp[i] += dp[i - coin];
                }
            }
        }
        for (int d : dp) {
            cout << d << " ";
        }
        cout << endl;
        return dp[amount];
    }
};
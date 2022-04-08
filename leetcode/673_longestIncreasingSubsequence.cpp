#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        ll n = nums.size();
        // where len[i] is the length of longest subsequence at index i
        ll len[n + 1];
        // where cts[i] is number of subsequences at index i
        ll cts[n + 1];
        for (int i = 0; i < n + 1; i++) {
            len[i] = 1, cts[i] = 1;
            for (int j = 0; j < i; j++) {
                if (i == n || nums[j] < nums[i]) {
                    if (len[j] >= len[i]) {
                        // found a longer subsequence. Extending longest subsequence
                        len[i] = len[j] + 1;
                        cts[i] = cts[j];
                    } else if (len[j] + 1 == len[i]) {
                        // we found another subsequence that can stil increase with current number
                        cts[i] += cts[j];
                    }
                }
            }
        }
        return cts[n];
    }
};
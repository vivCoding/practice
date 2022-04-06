#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto p = upper_bound(nums.begin(), nums.end(), target);
        if (p == nums.begin() || (p != nums.begin() && *(p - 1) != target)) {
            return { -1 , -1 };
        }
        int pr = p - nums.begin();
        int pl = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        pr = pl == pr ? pr : pr - 1;
        return { pl, pr };
    }
};
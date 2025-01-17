#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k
*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long mxSum = 0;
        int n = nums.size();
        unordered_map<int, int> mp;
        int bad = 0;
        long long currSum = 0;
        for (int i = 0; i < k; i++) {
            currSum += nums[i];
            mp[nums[i]]++;
            if (mp[nums[i]] == 2) {
                bad++;
            }
        }
        if (bad == 0) {
            mxSum = max(currSum, mxSum);
        }
        for (int i = k; i < n; i++) {
            currSum -= nums[i - k];
            mp[nums[i - k]]--;
            if (mp[nums[i - k]] == 1) {
                bad--;
            }
            currSum += nums[i];
            mp[nums[i]]++;
            if (mp[nums[i]] == 2) {
                bad++;
            }
            if (bad == 0) {
                mxSum = max(currSum, mxSum);
            }
        }
        return mxSum;
    }
};
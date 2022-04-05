#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://leetcode.com/problems/3sum-closest/
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int md = INT_MAX;
        int ms = 0;
        for (int i = 0; i < n; i++) {
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];
                if (currSum == target) return currSum;
                if (abs(target - currSum) < md) {
                    md = abs(target - currSum);
                    ms = currSum;
                }
                if (currSum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ms;
    }
};
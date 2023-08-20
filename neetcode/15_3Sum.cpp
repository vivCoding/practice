#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/3sum/
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            int sm = 0;
            while (j < k) {
                sm = nums[i] + nums[j] + nums[k];
                if (sm < 0) {
                    j++;
                } else if (sm > 0) {
                    k--;
                } else {
                    res.push_back({ nums[i], nums[j], nums[k] });
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    j++;
                    while(j < k && nums[k] == nums[k - 1]) k--;
                    k--;
                }
            }
        }
        return res;
    }
};
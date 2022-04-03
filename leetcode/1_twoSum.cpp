#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://leetcode.com/problems/two-sum/
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto p = m.find(target - nums[i]);
            if (p == m.end()) {
                m.insert(make_pair(nums[i], i));
            } else {
                res.push_back(p->second);
                res.push_back(i);
                return res;
            }
        }
        return res;
    }
};
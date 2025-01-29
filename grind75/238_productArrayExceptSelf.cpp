#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/product-of-array-except-self/description/
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int curr = 1;
        for (int i = 0; i < nums.size(); i++) {
            res[i] = curr;
            curr *= nums[i];
        }
        curr = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            res[i] *= curr;
            curr *= nums[i];
        }
        return res;
    }
};
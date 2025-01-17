#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/binary-search/
*/

class Solution {
public:
        int search(vector<int>& nums, int target) {
            int l = 0, r = nums.size() - 1;
            while (l < r - 1) {
                int m = l + (r - l) / 2;
                if (nums[m] < target) {
                    l = m;
                } else if (nums[m] > target) {
                    r = m;
                } else {
                    return m;
                }
            }
            if (nums[l] == target) return l;
            if (nums[r] == target) return r;
            return -1;
        }
};
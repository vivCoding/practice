#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, m = 0;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (target == nums[m]) return m;
            if (target < nums[m]) {
                if (nums[l] < nums[m]) {
                    if (target < nums[l]) {
                        l = m;
                    } else {
                        r = m;
                    }
                } else {
                    r = m;
                }
            } else {
                if (nums[m] < nums[r]) {
                    if (nums[r] < target) {
                        r = m;
                    } else {
                        l = m;
                    }
                } else {
                    l = m;
                }
            }
        }
        if (target == nums[l]) return l;
        else if (target == nums[r]) return r;
        return -1;
    }
};

// 1 2 3 4 5 6 7 8
// 3 4 5 6 7 8 1 2
// 7 8 1 2 3 4 5 6
// 8 1 2 3 4 5 6 7
// 4 5 6 7 8 1 2 3
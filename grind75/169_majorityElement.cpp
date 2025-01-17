#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/majority-element/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
            if (mp[num] > nums.size() / 2) {
                return num;
            }
        }
        return -1;
    }

    // uses constant space
    int majorityElement2(vector<int>& nums) {
        int ct = 0;
        int curr = nums[0];
        for (int num : nums) {
            if (ct == 0) {
                curr = num;
                ct = 1;
            } else if (curr == num) {
                ct++;
            } else {
                ct--;
            }
        }
        return curr;
    }
};

#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/contains-duplicate/
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() < 2) return false;
        unordered_set<int> st;
        st.reserve(nums.size());
        for (int x : nums) {
            if (st.find(x) != st.end()) {
                return true;
            }
            st.insert(x);
        }
        return false;
    }
};
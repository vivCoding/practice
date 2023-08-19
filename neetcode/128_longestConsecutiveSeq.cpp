#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/longest-consecutive-sequence/
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int x : nums) {
            st.insert(x);
        }
        int mx = 0;
        for (int num : st) {
            // make sure we are at beginning of sequence
            if (st.find(num - 1) == st.end()) {
                int ct = 1, x = num + 1;
                while (st.find(x) != st.end()) {
                    ct++, x++;
                }
                mx = max(mx, ct);
            }
        }
        return mx;
    }
};
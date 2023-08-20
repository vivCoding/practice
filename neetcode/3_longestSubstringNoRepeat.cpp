#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int mx = 0, ct = 0;
        int i = 0;
        for (char c : s) {
            while (st.find(c) != st.end()) {
                st.erase(s[i]);
                i++, ct--;
            }
            st.insert(c);
            ct++;
            mx = max(mx, ct);
        }
        return mx;
    }
};
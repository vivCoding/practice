#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int maxLength = 0, currLength = 0;
        int left = 0;
        for (char c : s) {
            while (st.find(c) != st.end()) {
                st.erase(s[left]);
                left++;
                currLength--;
            }
            st.insert(c);
            currLength++;
            maxLength = max(currLength, maxLength);
        }
        return maxLength;
    }
};
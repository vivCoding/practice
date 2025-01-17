#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/longest-palindrome/description/
*/

// ababab
// babaab

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        int total = 0;
        bool hasOdd = false;
        for (auto p : mp) {
            int ct = p.second;
            if (ct % 2 == 0) {
                total += ct;
            } else {
                total += ct - 1;
                hasOdd = true;
            }
        }
        return total + (hasOdd ? 1 : 0);
    }
};
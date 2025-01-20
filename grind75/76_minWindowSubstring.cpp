#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/minimum-window-substring/description/
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : t) mp[c]++;
        int left = 0, currLength = 0;
        int minLeft = 0, minLength = INT_MAX;
        unordered_map<char, int> curr;
        for (char c : s) {
            curr[c]++;
            currLength++;

            // ensure every letter in t is in substring
            bool good = true;
            for (auto p : mp) {
                if (curr[p.first] < p.second) {
                    good = false;
                    break;
                }
            }
            if (!good) continue;

            // if it is, see if we can shrink it
            while (good) {
                if (currLength < minLength) {
                    minLeft = left;
                    minLength = min(minLength, currLength);
                }
                curr[s[left]]--;
                currLength--;
                left++;
                // we're shrinking until we are missing letters from t
                for (auto p : mp) {
                    if (curr[p.first] < p.second) {
                        good = false;
                        break;
                    }
                }
            }
        }
        if (minLength == INT_MAX) return "";
        return s.substr(minLeft, minLength);
    }
};
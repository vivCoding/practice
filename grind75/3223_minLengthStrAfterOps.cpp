#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/minimum-length-of-string-after-operations/
*/

class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        int ct = 0;
        for (auto p : mp) {
            if (p.second % 2 == 0) {
                ct += 2;
            } else {
                ct += 1;
            }
        }
        return ct;
    }
};
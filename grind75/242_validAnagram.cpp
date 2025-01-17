#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/valid-anagram/
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }
        for (char c : t) {
            mp[c]--;
            if (mp[c] < 0) {
                return false;
            }
        }
        return true;
    }
};
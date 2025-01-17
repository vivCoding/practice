#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/ransom-note/
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mpr;
        for (char c : ransomNote) {
            mpr[c]++;
        }
        unordered_map<char, int> mpm;
        for (char c : magazine) {
            mpm[c]++;
        }
        for (auto p : mpr) {
            char c = p.first;
            int ct = p.second;
            if (mpm[c] < ct) {
                return false;
            }
        }
        return true;
    }
};
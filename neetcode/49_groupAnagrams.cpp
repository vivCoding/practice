#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/group-anagrams/
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for (string s : strs) {
            string w = s;
            sort(s.begin(), s.end());
            mp[s].push_back(w);
        }
        for (auto p : mp) {
            res.push_back(p.second);
        }
        return res;
    }
};
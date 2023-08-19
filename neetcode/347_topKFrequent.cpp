#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/top-k-frequent-elements/
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int x : nums) {
            mp[x]++;
        }
        // doing bucket sort to achieve O(n) time
        // we know that freq <= n, hence bucket size is n
        vector<vector<int>> b(n + 1);
        for (auto p : mp) {
            b[p.second].push_back(p.first);
        }
        // remember, answer is guaranteed to be unique (aka no ambiguous ties in final res)
        vector<int> res;
        for (int i = n; i >= 0; i--) {
            if (res.size() >= k) break;
            if (!b[i].empty()) {
                res.insert(res.end(), b[i].begin(), b[i].end());
            }
        }
        return res;
    }
};
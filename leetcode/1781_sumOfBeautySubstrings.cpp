#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
 */

class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            unordered_map<char, int> m;

            for (int j = i; j < s.length(); j++) {
                auto p = m.find(s[j]);
                if (p == m.end()) {
                    m.insert(pair<char, int>(s[j], 1));
                } else {
                    p->second++;
                }
                int least = 999, most = 0;
                for (auto it : m) {
                    least = min(least, it.second);
                    most = max(most, it.second);
                }
                sum += most - least;
            }
        }
        return sum;
    }
};

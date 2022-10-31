#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/minimum-window-substring/
*/

string minWindow(string s, string t) {
    if (s == t) return s;
    if (s.size() < t.size()) return "";
    if (s.size() == 1) return "";
    unordered_map<char, int> mp, curr;
    for (char c : t) {
        mp[c]++, curr[c] = 0;
    }
    int i = 0;
    int m1 = 0, m2 = INT_MAX;
    int ct = 0;

    for (int j = 0; j < s.size(); j++) {
        if (mp.find(s[j]) != mp.end()) {
            mp[s[j]]--;
            if (mp[s[j]] >= 0) ct++;
        }
        if (ct == t.size()) {
            while (i <= j && ct == t.size()) {
                if (j - i < m2 - m1) {
                    m2 = j, m1 = i;
                }
                if (mp.find(s[i]) != mp.end()) {
                    mp[s[i]]++;
                    if (mp[s[i]] > 0) {
                        ct--;
                    }
                }
                i++;
            }
        }
    }

    if (m2 == INT_MAX) return "";
    return s.substr(m1, m2 - m1 + 1);
}

int main() {
    // string s = "aa";
    // string t = "a";
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/remove-k-digits/
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.length() <= k) {
            return "0";
        }
        stack<char> s;
        ll n = num.length();
        for (int i = 0; i < n; i++) {
            while (!s.empty() && k > 0 && num[i] < s.top()) {
                s.pop();
                k--;
            }
            if (!(s.empty() && num[i] == '0')) {
                s.push(num[i]);
            }
        }
        while (k && !s.empty()) {
            s.pop();
            k--;
        }
        if (s.empty()) {
            return "0";
        }
        string res;
        while (!s.empty()) {
            res += s.top();
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/valid-palindrome/
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        while (i <= j) {
            while (i < n - 1 && !isalnum(s[i])) i++;
            while (j > 0 && !isalnum(s[j])) j--;
            if (i > j) break;
            if (tolower(s[i]) != tolower(s[j])) return false;
            i++, j--;
        }
        return true;
    }
};

#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/first-bad-version/
*/

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 0, r = n;
        while (l < r - 1) {
            int m = l + (r - l) / 2;
            if (isBadVersion(m)) {
                r = m;
            } else {
                l = m;
            }
        }
        if (isBadVersion(l)) return l;
        if (isBadVersion(r)) return r;
        return -1;
    }
};
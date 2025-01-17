#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/climbing-stairs/description/
*/


/*

0: 1
1: 1
2: 2
3: 3
4: 4


*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;
        int ct = 1;
        int prev = 1;
        for (int i = 2; i <= n; i++) {
            int temp = ct;
            ct += prev;
            prev = temp;
        }
        return ct;
    }
};
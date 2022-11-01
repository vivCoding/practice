#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/trapping-rain-water/
*/

int trap(vector<int>& height) {
    int n = height.size();
    if (n < 3) return 0;
    int mxl[n], mxr[n];
    for (int i = 0; i < n; i++) {
        if (i < 3) mxl[i] = 0, mxr[n - i - 1] = 0;
        else {
            mxl[i] = max(mxl[i - 2], mxl[i - 1]);
            mxr[i] = max(mxr[n - i - 1], mxr[i - 1]);
        }
    }


    int lastMax = 0;
    int ct = 0, lastFilled = 0;
    for (int x : height) {
        if (x < lastMax) {
            lastFilled += lastMax - x;
        } else {
            ct += lastFilled;
        }
    }
    return ct;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << LONG_MAX << endl;
    cout << LONG_LONG_MAX << endl;
    return 0;
}
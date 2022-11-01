#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int mnl[n], mnr[n];
    int mn = INT_MAX, mi = 0;
    for (int i = 0; i < n; i++) {
        mnl[i] = mi;
        if (heights[i] <= mn) {
            mi = i;
            mn = heights[i];
        }
    }
    mn = INT_MAX, mi = n;
    for (int i = n - 1; i >= 0; i--) {
        mnr[i] = mi;
        if (heights[i] <= mn) {
            mi = i;
            mn = heights[i];
        }
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, heights[i] * (mnr[i] - mnl[i]));
    }
    return mx;
}


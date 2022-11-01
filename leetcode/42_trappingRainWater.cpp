#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/trapping-rain-water/
*/

int trap(vector<int>& height) {
    int n = height.size();
    stack<pair<int, int>> s1, s2;
    for (int i = n - 1; i >= 0; i--) {
        while (!s1.empty() && s1.top().first < height[i]) {
            s1.pop();
        }
        s1.push({height[i], i});
        if (s2.empty() || height[i] > s2.top().first) {
            s2.push({height[i], i});
        }
    }
    int ct = 0;
    while (s1.size() > 1) {
        auto a = s1.top();
        s1.pop();
        auto b = s1.top();
        for (int i = a.second + 1; i < b.second; i++) {
            ct += a.first - height[i];
        }
    }
    while (s2.size() > 1) {
        auto a = s2.top();
        s2.pop();
        if (a.second < s1.top().second) continue;
        auto b = s2.top();
        for (int i = a.second + 1; i < b.second; i++) {
            ct += b.first - height[i];
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
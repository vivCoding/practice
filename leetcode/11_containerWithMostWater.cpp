#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/container-with-most-water/
*/

int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int mx = 0;
    while (l < r) {
        mx = max(mx, min(height[l], height[r]) * (r - l));
        if (height[l] <= height[r]) l++;
        else if (height[r] < height[l]) r--;
    }
    return mx;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> height ={1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    return 0;
}
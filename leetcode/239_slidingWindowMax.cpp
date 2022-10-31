#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/minimum-window-substring/
*/

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    multiset<pair<int, int>> ms;
    for (int i = 0; i < k; i++) {
        ms.insert({nums[i], -i});
    }
    res.push_back(ms.rbegin()->first);
    for (int i = k; i < nums.size(); i++) {
        ms.insert({nums[i], -i});
        auto p = ms.rbegin();
        while (abs(p->second) < i - k + 1) {
            ms.erase(--ms.end());
            p = ms.rbegin();
        }
        res.push_back(p->first);
    }
    return res;
}

int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6, 7};
    // vector<int> nums = {1};
    auto v = maxSlidingWindow(nums, 3);
    for (auto p : v) {
        cout << p << " ";
    }
    return 0;
}
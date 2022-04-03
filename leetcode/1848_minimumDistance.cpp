#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://leetcode.com/problems/minimum-distance-to-the-target-element/
 */

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                res = min(abs(i - start), res);
            }
        }
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, target, start; cin >> n >> target >> start;
    vector<int> nums;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums.push_back(temp);
    }
    Solution s;
    int v = s.getMinDistance(nums, target, start);
    cout << v << endl;
    return 0;
}
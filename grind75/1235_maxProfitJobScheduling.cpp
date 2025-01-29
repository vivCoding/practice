#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/maximum-profit-in-job-scheduling/description/
*/

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int, int>> endTimeIdx(n);
        for (int i = 0; i < n; i++) {
            endTimeIdx.push_back({endTime[i], i});
        }
        sort(endTimeIdx.begin(), endTimeIdx.end());
        // can optimize to use an array rather than map
        map<int, int> mp;
        int lastProfit = 0;
        for (int i = 0; i < n; i++) {
            int et = endTimeIdx[i].first;
            int idx = endTimeIdx[i].second;
            if (i == 0) {
                mp[et] = profit[idx];
                continue;
            }
            auto it = mp.lower_bound(startTime[idx]);
            int prevProfit = 0;
            if (it != mp.end() && it->first == startTime[idx]) {
                prevProfit =  it->second;
            } else if (it == mp.begin()) {
                prevProfit = 0;
            } else {
                prevProfit = prev(it)->second;
            }
            // compare to the previous one
            mp[et] = max(endTimeIdx[i - 1].second, prevProfit + profit[i]);
        }
        return mp[endTimeIdx[n - 1].first];
    }
};
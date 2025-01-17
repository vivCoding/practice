#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/insert-interval/description/
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> res;

        int i = 0;
        int start = newInterval[0], end = newInterval[1];

        for (i; i < n; i++) {
            if (intervals[i][0] <= start && start <= intervals[i][1]) {
                start = intervals[i][0];
                break;
            }
            if (start < intervals[i][0]) {
                break;
            }
            res.push_back(intervals[i]);
        }

        for (i; i < n; i++) {
            if (intervals[i][0] <= end && end <= intervals[i][1]) {
                end = intervals[i][1];
            }
            if (end < intervals[i][0]) {
                break;
            }
        }

        res.push_back({start, end});

        for (i; i < n; i++) {
            res.push_back(intervals[i]);
        }
        return res;
    }
};
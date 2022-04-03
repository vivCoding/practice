#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://leetcode.com/problems/moving-stones-until-consecutive-ii/
 * UNSOLVED
 */

class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int gaps = 0;
        int n = stones.size();
        for (int i = 1; i < n; i++) {
            gaps += stones[i] - stones[i - 1] - 1;
        }
        int max_moves = max(gaps - (stones[1] - stones[0] - 1), gaps - (stones[n - 1] - stones[n - 2] - 1));
        
        return {0, max_moves};
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> stones;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        stones.push_back(temp);
    }
    Solution s;
    auto v = s.numMovesStonesII(stones);
    for (auto res : v) {
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
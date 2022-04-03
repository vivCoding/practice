#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;
const string alphabet = "abcdefghijklmnopqrstuvwxyz";

/*
 * Problem: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
 */


class Solution {
public:
    string getSmallestString(int n, int k) {
        int minChar = 97, maxChar = 122, offset = 96;
        char chars[n + 1];
        for (int i = 0; i < n; i++) chars[i] = 97;
        int sum = n;
        int i = n - 1;
        while (sum < k) {
            sum -= chars[i] - offset;
            int val = min((int) 26, k - sum) + offset;
            chars[i] = val;
            sum += val - offset;
            i--;
        }
        chars[n] = '\0';
        return chars;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    cout << Solution().getSmallestString(n, k) << endl;
    return 0;
}
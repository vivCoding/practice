#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/01-matrix/
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, 1e4));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    if (i < n - 1) res[i + 1][j] = 1;
                    if (j < m - 1) res[i][j + 1] = 1;
                }
                if (mat[i][j] == 1) {
                    if (i < n - 1 && res[i + 1][j] == 1) res[i + 1][j] = min(res[i + 1][j], res[i][j] + 1);
                    if (j < m - 1) res[i][j + 1] = min(res[i][j + 1], res[i][j] + 1);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    if (i > 0) res[i - 1][j] = 1;
                    if (j > 0) res[i][j - 1] = 1;
                }
                if (mat[i][j] == 1) {
                    if (i > 0) res[i - 1][j] = min(res[i - 1][j], res[i][j] + 1);
                    if (j > 0) res[i][j - 1] = min(res[i][j - 1], res[i][j] + 1);
                }
            }
        }
        return res;
    }
};
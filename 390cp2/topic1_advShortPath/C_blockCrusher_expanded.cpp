#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/knssyb/problems/blockcrusher
*/

int charToDigit(char c) {
    return c - 48;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h, w; cin >> h >> w;
    while (h != 0 && w != 0) {
        string mp[h] = {};
        int dp[h][w] = {};
        // initialize dp table
        for (int i = 0; i < h; i++) {
            cin >> mp[i];
            for (int j = 0; j < w; j++) {
                dp[i][j] = 12000;
            }
        }
        int dirs[][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
        // used for the very last row
        int lastIdx = 0, lastMin = INT_MAX;
        for (int i = 0; i < h; i++) {
            // update dp table for the current row
            for (int j = 0; j < w; j++) {
                int val = charToDigit(mp[i][j]);
                if (i == 0) {
                    dp[i][j] = val;
                } else {
                    for (auto p : dirs) {
                        int ny = i + p[0], nx = j + p[1];
                        if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                            dp[i][j] = min(dp[ny][nx] + val, dp[i][j]);
                        }
                    }
                }
            }
            // for all rows before, update the dp table (need to account for fracture going up and down)
            for (int k = i; i >= 0; i--) {
                for (int j = 0; j < w; j++) {
                    int val = charToDigit(mp[k][j]);
                    for (auto p : dirs) {
                        int ny = k + p[0], nx = j + p[1];
                        if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                            dp[k][j] = min(dp[ny][nx] + val, dp[k][j]);
                        }
                    }
                    // if on last row, get the idx of the lowest fracture score
                    if (i == h - 1) {
                        if (dp[i][j] < lastMin) lastIdx = j;
                        lastMin = min(dp[i][j], lastMin);
                    }
                }
            }
        }
        // backtrack and update block
        int cy = h - 1, cx = lastIdx;
        mp[cy][cx] = ' ';
        while (cy != 0) {
            dp[cy][cx] = INT_MAX;
            int lx, ly, lastMin = INT_MAX;
            // the last minimum value in the dp table (starting from last known position) would be where fracture occurs
            for (auto p : dirs) {
                int ny = cy + p[0], nx = cx + p[1];
                if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
                    if (dp[ny][nx] < lastMin) lx = nx, ly = ny;
                    lastMin = min(dp[ny][nx], lastMin);
                }
            }
            mp[ly][lx] = ' ';
            cx = lx, cy = ly;
        }
        // output
        for (auto s : mp) {
            cout << s << endl;
        }
        cout << endl;
        cin >> h >> w;
    }
    return 0;
}

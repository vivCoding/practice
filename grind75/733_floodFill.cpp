#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/flood-fill/
*/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc });
        pair<int, int> dirs[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto next = q.front();
            q.pop();
            if (image[next.first][next.second] == color) continue;
            image[next.first][next.second] = color;
            for (auto dir : dirs) {
                pair<int, int> newCoord = {next.first + dir.first, next.second + dir.second};
                if (newCoord.first >= 0 && newCoord.first < n &&
                    newCoord.second >= 0 && newCoord.second < m &&
                    image[newCoord.first][newCoord.second] == oldColor
                ) {
                    q.push(newCoord);
                }
            }
        }
        return image;
    }
};
#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/yn5g3i/problems/peg
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string board[7] = {};
    vector<pair<int, int>> pos;
    for (int i = 0; i < 7; i++) {
        cin >> board[i];
        if (i < 2 || i > 4) {
            board[i] = "  " + board[i] + "  ";
        }
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == '.') {
                pos.push_back({i, j});
            }
        }
    }
    int ct = 0;
    int dirs[4][2] = {{-2, 0}, {2, 0}, {0, 2}, {0, -2}};
    for (auto p : pos) {
        int i = p.first;
        int j = p.second;
        for (auto dir : dirs) {
            if (i + dir[0] >= 0 && i + dir[0] < 7 && board[i + dir[0]][j] == 'o' && board[i + dir[0] / 2][j] == 'o') {
                ct++;
            }
            if (j + dir[1] >= 0 && j + dir[1] < 7 && board[i][j + dir[1]] == 'o' && board[i][j + dir[1] / 2] == 'o') {
                ct++;
            }
        }
    }
    cout << ct << endl;
    return 0;
}
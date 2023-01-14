#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/yn5g3i/problems/gold
*/

int n, m;
vector<string> board;
int ct = 0;
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y) {
    if (board[x][y] == 'G') {
        ct++;
    }
    board[x][y] = 'x';
    bool good = true;
    for (auto dir : dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] == 'T') {
            good = false;
            break;
        }
    }
    if (good) {
        for (auto dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (
                nx >= 0 && nx < n && ny >= 0 && ny < m &&
                board[nx][ny] != 'x' && board[nx][ny] != '#'
            ) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    board.resize(n);
    int xs, ys;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'P') {
                xs = i, ys = j;
            }
        }
    }
    board[xs][ys] = 'x';
    dfs(xs, ys);
    cout << ct << endl;
    return 0;
}
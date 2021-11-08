#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1193
*/

signed main() {
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    char map[n][m];
    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'A') {
                start.first = i;
                start.second = j;
                map[i][j] = 'v';
            } else if (map[i][j] == 'B') {
                end.first = i;
                end.second = j;
            }
        }
    }

    pair<char, pair<int, int>> parents[n][m];
    queue<pair<int, int>> q;
    q.push(start);

    pair<int, int> current;
    while (true) {
        if (q.empty()) {
            cout << "NO" << endl;
            return 0;
        }
        current = q.front();
        q.pop();
        if (current.first == end.first && current.second == end.second) {
            break;
        }

        pair<int, int> left = pair<int, int>(current.first, max(current.second - 1, (long) 0));
        if (map[left.first][left.second] != 'v' && map[left.first][left.second] != '#') {
            map[left.first][left.second] = 'v';
            parents[left.first][left.second] = pair<char, pair<int, int>>('L', current);
            q.push(left);
        }
        pair<int, int> right = pair<int, int>(current.first, min(current.second + 1, m - 1));
        if (map[right.first][right.second] != 'v' && map[right.first][right.second] != '#') {
            map[right.first][right.second] = 'v';
            parents[right.first][right.second] = pair<char, pair<int, int>>('R', current);
            q.push(right);
        }
        pair<int, int> up = pair<int, int>(max(current.first - 1, (long) 0), current.second);
        if (map[up.first][up.second] != 'v' && map[up.first][up.second] != '#') {
            map[up.first][up.second] = 'v';
            parents[up.first][up.second] = pair<char, pair<int, int>>('U', current);
            q.push(up);
        }
        pair<int, int> down = pair<int, int>(min(current.first + 1, n - 1), current.second);
        if (map[down.first][down.second] != 'v' && map[down.first][down.second] != '#') {
            map[down.first][down.second] = 'v';
            parents[down.first][down.second] = pair<char, pair<int, int>>('D', current);
            q.push(down);
        }
    }

    stack<char> dirs;
    pair<char, pair<int, int>> pathCurrent = parents[current.first][current.second];
    int count = 1;
    while (true) {
        dirs.push(pathCurrent.first);
        if (pathCurrent.second.first == start.first && pathCurrent.second.second == start.second) {
            break;
        }
        pathCurrent = parents[pathCurrent.second.first][pathCurrent.second.second];
        count++;
    }
    cout << "YES" << endl << count << endl;
    while (!dirs.empty()) {
        cout << dirs.top();
        dirs.pop();
    }

    return 0;
}
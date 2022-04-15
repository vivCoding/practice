#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1192
*/

int n, m;

void discover(int i, int j, bool** discovered, char** mp) {
    if (i < 0 || i >= n || j < 0 || j >= m || mp[i][j] == '#' || discovered[i][j]) return;
    discovered[i][j] = true;
    discover(i - 1, j, discovered, mp);
    discover(i + 1, j, discovered, mp);
    discover(i, j - 1, discovered, mp);
    discover(i, j + 1, discovered, mp);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    char** mp = new char*[n];
    bool** discovered = new bool*[n];
    bool found = false;
    for (int i = 0; i < n; i++) {
        mp[i] = new char[m];
        discovered[i] = new bool[m];
        for (int j = 0; j < m; j++) {
            cin >> mp[i][j];
            discovered[i][j] = false;
            if (mp[i][j] == '.') {
                found = true;
            }
        }
    }
    if (!found) {
        cout << 0 << endl;
        return 0;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '.') {
                if (discovered[i][j]) {
                    continue;
                } else {
                    count++;
                    discover(i, j, discovered, mp);
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void see(T&... args) { ((cin >> args), ...); }
template<typename... T>
void put(T&&... args) { ((cout << args), ...);}
template<typename... T>
void puts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
typedef unordered_map<ll, ll> umll;
#define vc vector
#define um unordered_map
#define us unordered_set
#define rep(i, a, b, v) for (int i = a; i < b; i += v)
#define rrep(i, a, b, v) for (int i = a; i >= b; i -= v)
#define all(x) x.begin(), x.end()
#define setpr(x) cout << setprecision(x) << fixed
const ll LLMAX = LONG_LONG_MAX / 2, LLMIN = LONG_LONG_MIN / 2;
const ll MOD9 = 1e9 + 7;
int charToDigit(char c) { return c - 48; }

/*
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/knssyb/problems/blockcrusher
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h, w; see(h, w);
    while (h != 0 && w != 0) {
        string mp[h] = {};
        int dp[h][w] = {};
        rep(i, 0, h, 1) {
            see(mp[i]);
            // initialize dp table
            rep(j, 0, w, 1) {
                dp[i][j] = 12000;
            }
        }
        int dirs[][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1, 1}, {-1, 1}, {-1, -1}, {1, -1}};
        // used for the very last row
        int lastIdx = 0, lastMin = INT_MAX;
        rep(i, 0, h, 1) {
            // update dp table for the current row
            rep(j, 0, w, 1) {
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
            rrep(k, i, 0, 1) {
                rep(j, 0, w, 1) {
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
            putl(s);
        }
        putl();
        see(h, w);
    }
    return 0;
}

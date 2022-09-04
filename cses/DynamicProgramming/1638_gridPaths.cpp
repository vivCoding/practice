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
#define all(x) x.begin(), x.end()
#define setpr(x) cout << setprecision(x) << fixed
const ll LLMAX = LONG_LONG_MAX / 2, LLMIN = LONG_LONG_MIN / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1638
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; see(n);
    char board[n][n];
    rep(x, 0, n, 1) {
        rep(y, 0, n, 1) {
            see(board[x][y]);
        }
    }
    int dp[n][n]; dp[0][0] = board[0][0] == '.';
    rep(x, 0, n, 1) {
        rep(y, 0, n, 1) {
            if (x == 0 && y == 0) continue;
            dp[x][y] = 0;
            if (board[x][y] == '*') continue;
            if (x > 0 && board[x - 1][y] == '.') {
                dp[x][y] += dp[x - 1][y] % MOD9;
            }
            if (y > 0 && board[x][y - 1] == '.') {
                dp[x][y] += dp[x][y - 1] % MOD9;
            }
        }
    }
    putl(dp[n - 1][n - 1] % MOD9);
    return 0;
}
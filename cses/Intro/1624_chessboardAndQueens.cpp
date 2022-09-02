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
 * Problem: https://cses.fi/problemset/task/1624
*/

char board[8][8];
ll ct = 0;
vc<pll> queens;

void rec(int x) {
    if (queens.size() == 8) {
        ct++;
        return;
    }
    rep(y, 0, 8, 1) {
        if (board[x][y] == '.') {
            bool bad = false;
            for (pll queen : queens) {
                if (y == queen.second || abs(queen.first - x) == abs(queen.second - y)) {
                    bad = true; 
                    break;
                }
            }
            if (!bad) {
                queens.push_back({x, y});
                rec(x + 1);
                queens.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    queens.reserve(8);
    rep(x, 0, 8, 1) {
        rep(y, 0, 8, 1) {
            see(board[x][y]);
        }
    }
    rec(0);
    putl(ct);
    return 0;
}
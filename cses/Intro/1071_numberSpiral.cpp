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
 * Problem: https://cses.fi/problemset/task/1071
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; see(t);
    rep(_, 0, t, 1) {
        int y, x; see(y, x);
        ll mx = max(y, x);
        ll corner;
        if (mx == 1) {
            corner = 1;
        } else {
            corner = 1 + (mx - 1) * mx;
        }
        if (y == x) {
            putl(corner);
        } else if (mx == y) {
            putl(corner + (mx - x) * (mx % 2 == 0 ? 1 : -1));
        } else if (mx == x) {
            putl(corner + (mx - y) * (mx % 2 == 0 ? -1 : 1));
        }
    }
    return 0;
}
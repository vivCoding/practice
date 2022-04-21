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
 * Problem: https://codeforces.com/contest/1669/problem/G
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q; see(q);
    while (q--) {
        ll n, m; see(n, m);
        char g[m][n];
        rep(y, 0, n, 1) {
            rep(x, 0, m, 1) {
                see(g[x][y]);
            }
        }
        rep(x, 0, m, 1) {
            ll next = n;
            for (ll y = n - 1; y >= 0; y--) {
                if (g[x][y] == 'o') {
                    next = y; 
                } else if (g[x][y] == '*') {
                    g[x][next - 1] = '*';
                    g[x][y] = y == next - 1 ? '*' : '.';
                    next--;
                }
            }
        }
        rep(y, 0, n, 1) {
            rep(x, 0, m, 1) {
                put(g[x][y]);
            }
            putl();
        }
    }
    return 0;
}
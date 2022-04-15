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
// #define LOCAL

/*
 * Problem: https://codeforces.com/problemset/problem/1621/B
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    #endif
    ll q; see(q);
    while(q--) {
        ll n; see(n);
        ll sm = INT_MAX, smc = INT_MAX;
        ll mx = INT_MIN, mxc = INT_MAX;
        ll lamt = 0, lc = INT_MAX;
        ll l, r, c;
        rep(i, 0, n, 1) {
            see(l, r, c);
            if (l <= sm) {
                if (l < sm) {
                    smc = c;
                } else {
                    smc = min(smc, c);
                }
                sm = l;
            }
            if (r >= mx) {
                if (r > mx) {
                    mxc = c;
                } else {
                    mxc = min(mxc, c);
                }
                mx = r;
            }
            if (r - l >= lamt) {
                if (r - l > lamt) {
                    lc = c;
                } else {
                    lc = min(lc, c);
                }
                lamt = r - l;
            }
            ll amt = mx - sm, cost = smc + mxc;
            if (amt == lamt) {
                putl(min(cost, lc));
            } else if (amt > lamt) {
                putl(cost);
            } else {
                putl(lc);
            }
        }
    }
    return 0;
}
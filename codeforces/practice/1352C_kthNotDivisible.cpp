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
 * Problem: https://codeforces.com/problemset/problem/1352/C
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; see(t);
    while(t--) {
        ll n, k; see(n, k);
        ll l = 1, r = LLMAX;
        ll m = 0;
        bool found = false;
        while (r - l > 1) {
            m = l + (r - l) / 2;
            ll x = m - (m / n);
            if (x == k) {
                if (m % n == 0) {
                    r = m;
                } else {
                    putl(m);
                    found = true;
                    break;
                }
            } else if (x > k) {
                r = m;
            } else {
                l = m;
            }
        }
        if (!found) {
            if (l - (l / n) == k) {
                putl(l);
            } else {
                putl(r);
            }
        }
    }
    return 0;
}
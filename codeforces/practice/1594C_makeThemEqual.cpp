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
 * Problem: https://codeforces.com/problemset/problem/1594/C
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q; see(q);
    while (q--) {
        ll n; char c; see(n, c);
        string s; see(s);
        vll v; v.reserve(n);
        ll ct = 0;
        rep(i, 0, n, 1) {
            if (s[i] != c) {
                v.push_back(i + 1);
            }
        }
        if (v.size() == 0) {
            putl(0);
            continue;
        } else if (v.size() == 1) {
            putl(1);
            if (v.back() == n) {
                putl(v.back() - 1);
            } else {
                putl(v.back() + 1);
            }
        } else if (v.size() >= 2) {
            if (v[v.size() - 2] + 1 == v.back()) {
                putl(2);
                putl(v.back() - 1, v.back());
            }
        }
    }
    return 0;
}
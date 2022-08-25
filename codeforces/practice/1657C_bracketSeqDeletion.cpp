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
 * Problem: https://codeforces.com/problemset/problem/1657/C
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; see(t);
    while(t--) {
        ll n; see(n);
        string s; see(s);
        vll v; v.reserve(n);
        ll ni = 0;
        ll ct = 0;
        for (char c : s) {
            if (ni != 0 && c == v[0]) {
                v[ni] = c;
                ni++;
                bool good = true;
                rep(i, 0, ni, 1) {
                    if (i == ni - i - 1) {
                        break;
                    }
                    if (v[i] != v[ni - i - 1]) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    ct++;
                    ni = 0;
                }
            } else {
                if (ni != 0 && v[0] == '(' && c == ')') {
                    ni = 0;
                    ct++;
                } else {
                    v[ni] = c;
                    ni++;
                }
            }
        }
        putl(ct, ni);
    }
    return 0;
}
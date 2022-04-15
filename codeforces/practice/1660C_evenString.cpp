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
const ll LLMAX = LONG_LONG_MAX / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://codeforces.com/problemset/problem/1660/C
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; see(t);
    while (t--) {
        string s; see(s);
        um<char, bool> mp;
        ll ct = 0;
        for (char c : s) {
            if (!mp[c]) {
                mp[c] = true;
            } else {
                // we have a pair
                ct += 2;
                mp.clear();
            }
        }
        putl((ll) s.length() - ct);
    }
    return 0;
}
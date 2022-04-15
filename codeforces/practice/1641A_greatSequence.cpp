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
 * Problem: https://codeforces.com/problemset/problem/1641/A
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q; see(q);
    while (q--) {
        ll n, x; see(n, x);
        unordered_multiset<ll> ms;
        ms.reserve(n);
        multiset<ll> oms;
        ll temp;
        rep(i, 0, n, 1) {
            see(temp);
            ms.insert(temp);
            oms.insert(temp);
        }
        for (ll num : oms) {
            auto p = ms.find(num * x);
            auto self = ms.find(num);
            if (p != ms.end() && self != ms.end()) {
                ms.erase(p);
                ms.erase(self);
            }
        }
        putl(ms.size());
    }
    return 0;
}
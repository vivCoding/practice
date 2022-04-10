#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void see(T&... args) { ((cin >> args), ...); }
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
typedef unordered_map<ll, ll> umll;
#define um unordered_map;
#define vc vector;
const ll LLMAX = LONG_LONG_MAX / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://codeforces.com/problemset/problem/69/A
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; see(n);
    ll sx = 0, sy = 0, sz = 0;
    ll x, y, z;
    for (int i = 0; i < n; i++) {
        see(x, y, z);
        sx += x, sy += y, sz += z;
    }
    if (sx == 0 && sy == 0 && sz == 0) {
        putl("YES");
    } else putl("NO");
    return 0;
}
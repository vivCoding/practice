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
 * Problem: https://codeforces.com/problemset/problem/500/A
*/

ll n, t;
vll g;

void dfs(ll next) {
    if (next + 1 == t) {
        putl("YES");
        exit(0);
    }
    if (next + 1 > t) {
        putl("NO");
        exit(0);
    }
    dfs(next + g[next]);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    see(n, t);
    g.reserve(n);
    rep(i, 0, n - 1, 1) {
        see(g[i]);
    }
    dfs(0);
    return 0;
}
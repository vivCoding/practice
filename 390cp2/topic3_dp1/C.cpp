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
#define rrep(i, a, b, v) for (int i = a; i >= b; i -= v)
#define all(x) x.begin(), x.end()
#define setpr(x) cout << setprecision(x) << fixed
const ll LLMAX = LONG_LONG_MAX / 2, LLMIN = LONG_LONG_MIN / 2;
const ll MOD9 = 1e9 + 7;
int charToDigit(char c) { return c - 48; }


/*
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/hy6v7c/problems/gigcombinatorics
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; see(n);
    ll ct = 0;
    ll ct1 = 0, ct2 = 0;
    ll k;
    rep(i, 0, n, 1) {
        see(k);
        if (k == 1) ct1++;
        // with new 2, pair with all old 1s and 2s. Add to sum
        else if (k == 2) ct2 = (ct2 + ct1 + ct2) % MOD9;
        else if (k == 3) ct = (ct + ct2) % MOD9;
    }
    putl(ct);
    return 0;
}
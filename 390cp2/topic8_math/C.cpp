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
const ll MOD9 = 1e9 + 9;
int charToDigit(char c) { return c - '0'; }


/*
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/jmdnx8/problems/inversefactorial
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; see(s);

    int x = 0;
    for (char c : s) {
        x = (x * 10LL + charToDigit(c)) % MOD9;
    }
    int i = 1, fac = 1;
    while (fac != x) {
        fac = 1LL * fac * i % MOD9;
        i++;
    }
    // if it was 1, it was unchanged
    putl(i - (i != 1));
    return 0;
}
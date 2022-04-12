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
#define fr(i, a, b, v) for (int i = a; i < b; i += v)
#define all(x) x.begin(), x.end()
#define setpr(x) cout << setprecision(x) << fixed
const ll LLMAX = LONG_LONG_MAX / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://codeforces.com/problemset/problem/479/A
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c; see(a, b, c);
    if (a == 1 && b == 1 && c == 1) {
        putl(3);
    } else if (a >= b && a >= c) {
        if (b == 1 && c == 1) {
            putl(a * 2);
        } else if (b == 1 || c == 1) {
            putl(a * (b + c));
        } else {
            putl(a * b * c);
        }
    } else if (a <= b && b >= c) {
        if (a == 1 && c == 1) {
            putl(a + b + c);
        } else if (a == 1 && c != 1) {
            putl((a + b) * c);
        } else if (a != 1 && c == 1) {
            putl(a * (b + c));
        } else {
            putl(a * b * c);
        }
    } else if (a <= c && b <= c) {
        if (a == 1 && b == 1) {
            putl(2 * c);
        } else if (a == 1 || b == 1) {
            putl((a + b) * c);
        } else {
            putl(a * b * c);
        }
    }
    return 0;
}
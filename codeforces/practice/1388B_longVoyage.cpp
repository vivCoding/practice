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
#define um unordered_map;
#define vc vector;
#define fr(i, a, b, v) for (int i = a; i < b; i += v)
const ll LLMAX = LONG_LONG_MAX / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://codeforces.com/problemset/problem/1388/B
 */

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; see(t);
    int n;
    fr(ti, 0, t, 1) {
        see(n);
        fr (i, 1, n - (n / 4) + (n % 4 == 0), 1) {
            put(9);
        }
        fr(i, 0, n / 4 + 1 - (n % 4 == 0), 1) {
            put(8);
        }
        putl();
    }
    return 0;
}
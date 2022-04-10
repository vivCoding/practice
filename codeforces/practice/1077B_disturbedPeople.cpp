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
#define fr(i, a, b, v) for (int i = a; i < b; i += v)
const ll LLMAX = LONG_LONG_MAX / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://codeforces.com/problemset/problem/1077/B
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; see(n);
    ll a[n];
    fr(i, 0, n, 1) {
        see(a[i]);
    }
    ll ct = 0;
    fr(i, 1, n - 1, 1) {
        if (a[i - 1] == 1 && a[i + 1] == 1 && a[i] == 0) {
            ct++;
            a[i + 1] = 0;
        }
    }
    putl(ct);
    return 0;
}
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
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/cjwydw/problems/whostheboss
 * unsolved
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q; see(n, q);
    vector<vector<int>> v;
    int id, s, h;
    rep(i, 0, n, 1) {
        see(id, s, h);
        v.push_back({id, s, h});
    }
    sort(v.begin(), v.end(), [](vector<int> v1, vector<int> v2) {
        // return v1[1] == v2[1] ? v1[2] < v2[2] : v1[1] < v2[1];
        return v1[1] < v2[1];
    });
    for (auto p : v) {
        putl(p[0], p[1], p[2]);
    }
    int idq;
    rep(i, 0, q, 1) {
        see(idq);
    }
    return 0;
}
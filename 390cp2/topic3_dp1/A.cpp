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
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/hy6v7c/problems/keyboardconcert
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; see(n, m);
    um<int, us<int>> mp;
    int k, t;
    rep(i, 0, n, 1) {
        see(k);
        rep(j, 0, k, 1) {
            see(t);
            mp[t].insert(i);
        }
    }
    int notes[m];
    rep(i, 0, m, 1) see(notes[i]);

    int ct = 0;
    us<int> st = mp[notes[0]];
    rep(i, 1, m, 1) {
        us<int> newSt = st;
        auto curr = mp[notes[i]];
        // do intersections
        for (auto p : st) {
            if (curr.find(p) == curr.end()) {
                newSt.erase(p);
            }
        }
        for (auto p : curr) {
            if (st.find(p) == st.end()) {
                newSt.erase(p);
            }
        }
        // if intersection empty, we have no common instruments
        if (newSt.size() == 0) {
            ct++;
            st = curr;
        } else {
            st = newSt;
        }
    }
    putl(ct);
    return 0;
}
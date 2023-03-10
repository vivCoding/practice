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
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/v5ufp5/problems/pickupsticks
*/

int n, m;
unordered_map<int, vector<int>> mp;
unordered_map<int, bool> visited;
vector<int> res;

void dfs(int x) {
    visited[x] = true;
    for (auto p : mp[x]) {
        if (!visited[p]) {
            dfs(p);
        }
    }
    res.push_back(x);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    see(n, m);
    mp.reserve(n);
    visited.reserve(n);

    int a, b;
    unordered_set<int> st;
    rep(i, 0, m, 1) {
        see(a, b);
        mp[a].push_back(b);
        visited[a] = false;
        st.insert(b);
    }
    rep(i, 1, n + 1, 1) {
        if (st.find(i) == st.end()) {
            dfs(i);
        }
    }

    if (res.size() != n) {
        putl("IMPOSSIBLE");
    } else {
        rrep(i, n - 1, 0, 1) {
            putl(res[i]);
        }
    }

    return 0;
}
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
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/r5v27y/problems/supercomputer
*/

vector<int> fenwick;

int sum(int idx) {
    int total = 0;
    for (int i = idx; i > 0; i &= i-1) {
        total += fenwick[i - 1];
    }
    return total;
}

void update(int idx, int val) {
    for (int i = idx; i < fenwick.size(); i |= i + 1) {
        fenwick[i] += val;
    }
}

int getval(int idx) {
    return sum(idx + 1) - sum(idx);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; see(n, k);
    fenwick.resize(n + 1);
    rep(_, 0, k, 1) {
        char s; see(s);
        if (s == 'F') {
            int i; see(i);
            int val = getval(i);
            update(i, val == 0 ? 1 : -1);
            val = getval(i);
        } else {
            int l, r; see(l, r);
            putl(sum(r + 1) - sum(l));
        }
    }
}
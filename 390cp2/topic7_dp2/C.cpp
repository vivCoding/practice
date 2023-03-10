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
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/yyakc7/problems/favourable
*/

unordered_map<string, vc<string>> mp;
unordered_map<string, ll> mpe;

ll rec(string s) {
    if (mpe.find(s) != mpe.end()) {
        return mpe[s];
    }
    // use temp var to prevent side effects as updating
    ll ct = 0;
    for (auto sx : mp[s]) {
        ct += rec(sx);
    }
    mpe[s] = ct;
    return mpe[s];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; see(t);
    int n;
    rep(_, 0, t, 1) {
        see(n);
        string s; getline(cin, s); 
        rep(i, 0, n, 1) {
            getline(cin, s);
            string pg = s.substr(0, s.find(' '));
            s = s.substr(s.find(' ') + 1);
            if (s[0] == 'f' || s[0] == 'c') {
                mpe[pg] = s[0] == 'f';
            } else {
                int x, idx;
                while (s.length() > 0) {
                    idx = s.find(' ');
                    mp[pg].push_back(s.substr(0, idx == -1 ? s.length() : idx));
                    s = s.substr(idx == -1 ? s.length() : idx + 1);
                }
            }
        }
        putl(rec("1"));
        mp.clear(), mpe.clear();

    }
    return 0;
}
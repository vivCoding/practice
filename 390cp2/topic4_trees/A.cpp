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
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/cjwydw/problems/kitten
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k; see(k);
    um<int, int> mp;
    string s; getline(cin, s);
    getline(cin, s);
    while (s != "-1") {
        int a = stoi(s.substr(0, s.find(' ')));
        s = s.substr(s.find(' ') + 1);
        int b, idx;
        while (s.length() > 0) {
            idx = s.find(' ');
            b = stoi(s.substr(0, idx == -1 ? s.length() : idx));
            mp[b] = a;
            s = s.substr(idx == -1 ? s.length() : idx + 1);
        }
        getline(cin, s);
    }
    puts(k);
    while (true) {
        if (mp.find(k) == mp.end()) {
            putl();
            break;
        }
        puts(k = mp[k]);
    }
    return 0;
}
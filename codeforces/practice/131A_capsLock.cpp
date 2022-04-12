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
 * Problem: https://codeforces.com/problemset/problem/131/A
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; see(s);
    string word = s.length() == 1 ? "" : s.substr(1);
    bool shouldMod = true;
    for (char c : word) {
        if (islower(c)) {
            shouldMod = false;
            break;
        }
    }
    put((char) (shouldMod ? (islower(s[0]) ? toupper(s[0]) : tolower(s[0])) : s[0]));
    fr(c, 0, word.length(), 1) {
        put((char) (shouldMod ? tolower(word[c]) : word[c]));
    }
    return 0;
}
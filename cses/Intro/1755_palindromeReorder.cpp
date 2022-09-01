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
#define all(x) x.begin(), x.end()
#define setpr(x) cout << setprecision(x) << fixed
const ll LLMAX = LONG_LONG_MAX / 2, LLMIN = LONG_LONG_MIN / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1755
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; see(s);
    int n = s.length();
    um<char, int> mp; mp.reserve(n);
    for (char c : s) {
        mp[c]++;
    }
    char oddChar = ' ';
    for (auto x : mp) {
        if (x.second % 2 == 1) {
            if (oddChar != ' ' || n % 2 == 0) {
                putl("NO SOLUTION");
                return 0;
            }
            oddChar = x.first;
        }
    }
    char res[n];
    int i = 0, j = n - 1;
    for (auto x : mp) {
        if (x.first == oddChar) continue;
        rep(_, 0, x.second / 2, 1) {
            res[i] = x.first;
            i++;
        }
        rep(_, 0, x.second / 2, 1) {
            res[j] = x.first;
            j--;
        }
    }
    if (oddChar != ' ') {
        rep(_, 0, mp[oddChar], 1) {
            res[i] = oddChar;
            i++;
        }
    }
    for (char c : res) {
        put(c);
    }
    return 0;
}
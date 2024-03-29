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
 * Problem: https://cses.fi/problemset/task/1622
*/

us<string> usedWords;
vc<string> words;

void rec(string curr, string remaining) {
    if (remaining.length() == 0 && usedWords.find(curr) == usedWords.end()) {
        usedWords.insert(curr);
        words.push_back(curr);
        return;
    }
    rep(i, 0, remaining.length(), 1) {
        rec(curr + remaining[i],
            remaining.substr(0, i) + (i == remaining.length() - 1 ? "" : remaining.substr(i + 1))
        );
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    words.reserve(40320); // 8!
    usedWords.reserve(40320); // 8!
    string s; see(s);
    int n = s.length();
    sort(s.begin(), s.end());
    rec("", s);
    putl(words.size());
    for (string word : words) {
        putl(word);
    }
    return 0;
}
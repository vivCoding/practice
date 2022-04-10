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
const ll LLMAX = LONG_LONG_MAX / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://codeforces.com/problemset/problem/118/A
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; see(s);
    string res;
    string vowels = "aeiouy";
    string uppercase = "BCDFGHJKLMNPQRSTVWXZ";
    for (int i = 0; i < s.length(); i++) {
        if (vowels.find(tolower(s[i])) == -1) {
            res.push_back('.');
            if (isupper(s[i])) {
                res.push_back(tolower(s[i]));
            } else {
                res.push_back(s[i]);
            }
        }
    }
    putl(res);
    return 0;
}
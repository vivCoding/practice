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
 * Problem: https://codeforces.com/problemset/problem/58/A
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; see(s);
    string msg = "hello";
    string res = "";
    for (char c : s) {
        if (c == msg[0]) {
            msg = msg.erase(0, 1);
            res.push_back(c);
        }
    }
    if (res == "hello") {
        putl("YES");
    } else {
        putl("NO");
    }
    return 0;
}
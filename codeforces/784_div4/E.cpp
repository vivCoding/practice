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
 * Problem: https://codeforces.com/contest/1669/problem/E
 * UNSOLVED
*/

char letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k' };

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q; see(q);
    while (q--) {
        ll n; see(n);
        um<string, ll> mp;
        mp.reserve(121);
        string temp;
        string s = "ab";
        rep(i, 0, n, 1) {
            see(temp);
            s[0] = temp[0];
            for (char c : letters) {
                s[1] = c;
                mp[s]++;
            }
            s[1] = temp[1];
            for (char c : letters) {
                s[0] = c;
                mp[s]++;
            }
        }
        ll ct = 0;
        for (pair<string, ll> p : mp) {
            ct += p.second - 1;
            putl(p.first, p.second);
        }
        putl(ct);
    }
    return 0;
}
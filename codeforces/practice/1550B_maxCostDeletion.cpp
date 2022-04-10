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
#define um unordered_map;
#define vc vector;
#define fr(i, a, b, v) for (int i = a; i < b; i += v)
const ll LLMAX = LONG_LONG_MAX / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://codeforces.com/problemset/problem/1550/B
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ts; see(ts);
    string s;
    int n, a, b;
    fr(t, 0, ts, 1) {
        see(n, a, b, s);
        if (a == 0 && b == 0) {
            putl(0);
            continue;
        }
        if ((a >= 0 && b >= 0) || (a <= 0 && b >= 0)) {
            putl(n * (a + b));
        } else {
            char cf = s[0];
            int ct = 1;
            for (int i = 1; i < n; i++) {
                if (s[i] != cf) {
                    ct++;
                    while (i < n && s[i] != cf) {
                        i++;
                    }
                }
            }
            putl(n * a + ct * b);
        }
    }
    return 0;
}
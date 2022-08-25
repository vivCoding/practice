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
 * Problem: https://codeforces.com/contest/1669/problem/C
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q; see(q);
    while (q--) {
        ll n; see(n);
        ll goodOdd = true, goodEven = true;
        ll first = 0, second = 0;
        ll temp;
        rep(i, 0, n, 1) {
            see(temp);
            if (first == 0 && i == 0) {
                first = temp;
            } else if (second == 0 && i == 1) {
                second = temp;
            } else {
                if (i % 2 == 0 && temp % 2 != first % 2) {
                    goodOdd = false;
                } else if (i % 2 == 1 && temp % 2 != second % 2) {
                    goodEven = false;
                }
            }
        }
        if (!goodOdd || !goodEven) {
            putl("NO");
        } else putl("YES");
    }
    return 0;
}
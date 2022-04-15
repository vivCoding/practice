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
const ll LLMAX = LONG_LONG_MAX / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://codeforces.com/problemset/problem/1651/C
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; see(t);
    while (t--) {
        ll n; see(n);
        ll a[n], b[n];
        rep(i, 0, n, 1) {
            see(a[i]);
        }
        rep(i, 0, n, 1) {
            see(b[i]);
        }
        ll da = LLMAX, dan = LLMAX, db = LLMAX, dbn = LLMAX;
        rep(i, 0, n, 1) {
            da = min(da, abs(a[0] - b[i]));
            dan = min(dan, abs(a[n - 1] - b[i]));
            db = min(db, abs(b[0] - a[i]));
            dbn = min(dbn, abs(b[n - 1] - a[i]));
        }

        ll cost = da + dan + db + dbn;

        // finding the minimum cost combo
        cost = min(cost, abs(a[0] - b[0]) + dan + dbn);
        cost = min(cost, abs(a[0] - b[n - 1]) + dan + db);

        cost = min(cost, abs(a[n - 1] - b[0]) + da + dbn);
        cost = min(cost, abs(a[n - 1] - b[n - 1]) + da + db);

        cost = min(cost, abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]));
        cost = min(cost, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));
        putl(cost);
    }
    return 0;
}
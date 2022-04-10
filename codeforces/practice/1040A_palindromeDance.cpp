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
 * Problem: https://codeforces.com/problemset/problem/1040/A
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b; see(n, a, b);
    int ds[n];
    fr(i, 0, n, 1) {
        see(ds[i]);
    }
    int ct = 0;
    int ns = min(a, b), color = a < b ? 0 : 1;
    for (int i = 0; i < n; i++) {
        if (i == n - i - 1) {
            if (ds[i] == 2) {
                ct += ns, ds[i] = color;
            }
            continue;
        }
        int ds1 = ds[i];
        int ds2 = ds[n - i - 1];
        if (ds1 == 2 && ds2 == 2) {
            ct += ns * 2;
            ds[i] = color, ds[n - i - 1] = color;
        } else if (ds1 == 2 && ds2 != 2) {
            ct += ds2 == 0 ? a : b;
            ds[i] = ds2;
        } else if (ds1 != 2 && ds2 == 2) {
            ct += ds1 == 0 ? a : b;
            ds[n - i - 1] = ds1;
        } else if (ds1 != 2 && ds2 != 2 && ds1 != ds2) {
            putl(-1);
            return 0;
        }
    }
    putl(ct);
    return 0;
}
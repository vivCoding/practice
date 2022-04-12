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
 * Problem: https://codeforces.com/problemset/problem/1620/B
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q; see(q);
    while (q--) {
        ll w, h; see(w, h);
        ll k; see(k);
        ll b1 = INT_MAX, b2 = INT_MIN;
        ll temp;
        rep(i, 0, k, 1) {
            see(temp);
            b1 = min(b1, temp);
            b2 = max(b2, temp);
        }
        see(k);
        ll t1= INT_MAX, t2 = INT_MIN;
        rep(i, 0, k, 1) {
            see(temp);
            t1 = min(t1, temp);
            t2 = max(t2, temp);
        }
        ll area = INT_MIN;
        area = max(abs(b2 - b1) * h, abs(t2 - t1) * h);

        see(k);
        b1 = INT_MAX, b2 = INT_MIN;
        rep(i, 0, k, 1) {
            see(temp);
            b1 = min(b1, temp);
            b2 = max(b2, temp);
        }
        see(k);
        t1 = INT_MAX, t2 = INT_MIN;
        rep(i, 0, k, 1) {
            see(temp);
            t1 = min(t1, temp);
            t2 = max(t2, temp);
        }
        area = max(area, max(abs(b2 - b1) * w, abs(t2 - t1) * w));
        putl(area);
    }
    return 0;
}
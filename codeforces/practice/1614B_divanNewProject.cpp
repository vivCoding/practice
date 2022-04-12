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
 * Problem: https://codeforces.com/problemset/problem/1614/B
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q; see(q);
    while (q--) {
        ll n; see(n);
        multiset<pll> ms;
        ll temp;
        rep(i, 0, n, 1) {
            see(temp);
            ms.insert({ temp, i + 1 });
        }
        ll nums[n + 1];
        nums[0] = 0;
        ll next = 1;
        ll time = 0;
        for (auto p = ms.rbegin(); p != ms.rend(); p++) {
            nums[p->second] = next;
            time += 2 * abs(next) * p->first;
            next = next > 0 ? -next : -next + 1;
        }
        putl(time);
        for (ll num : nums) {
            puts(num);
        }
        putl();
    }
    return 0;
}
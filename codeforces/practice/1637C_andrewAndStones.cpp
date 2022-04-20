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
 * Problem: https://codeforces.com/problemset/problem/1637/C
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll t; see(t);
    while (t--) {
        ll n; see(n);
        ll nums[n];
        stack<ll> odds;
        bool allOnes = true;
        rep(i, 0, n, 1) {
            see(nums[i]);
            if (i != 0 && i != n - 1) {
                if (nums[i] % 2 == 1) {
                    odds.push(i);
                }
                if (allOnes && nums[i] != 1) {
                    allOnes = false;
                }
            }
        }
        if ((n == 3 && !odds.empty()) || allOnes) {
            putl(-1);
            continue;
        }
        ll ct = 0;
        rep(i, 1, n - 1, 1) {
            if (nums[i] <= 1) continue;
            ct += nums[i] / 2;
            nums[i] = nums[i] % 2;
        }
        while (!odds.empty() && odds.top()) {
            ct += (nums[odds.top()] + 1) / 2;
            nums[odds.top()] = 0;
            odds.pop();
        }
        putl(ct);
    }
    return 0;
}
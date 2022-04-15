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
 * Problem: https://codeforces.com/problemset/problem/1343/C
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll q; see(q);
    while (q--) {
        ll n; see(n);
        ll nums[n];
        rep(i, 0, n, 1) {
            see(nums[i]);
        }
        ll dp[n + 1];
        dp[0] = nums[0];
        ll lastPos = nums[0] > 0 ? 0 : -1, lastNeg = nums[0] < 0 ? 0 : -1;
        rep(i, 1, n + 1, 1) {
            int idx = nums[i - 1] > 0 ? lastNeg : lastPos;
            int idx2 = nums[i - 1] > 0 ? lastPos : lastNeg;
            if (nums[i - 1] > 0) {
                dp[i] = max(lastNeg == -1 ? nums[i - 1] : nums[i - 1] + dp[lastNeg], lastPos > lastNeg ? dp[lastPos] : LLMIN);
                // dp[i] = lastNeg == -1 ? nums[i - 1] : nums[i - 1] + dp[lastNeg];
            } else {
                dp[i] = max(lastPos == -1 ? nums[i - 1] : nums[i - 1] + dp[lastPos], lastNeg > lastPos ? dp[lastNeg] : LLMIN);
                // dp[i] = lastPos == -1 ? nums[i - 1] : nums[i - 1] + dp[lastPos];
            }
            if (nums[i - 1] > 0) {
                lastPos = i;
            } else {
                lastNeg = i;
            }
        }
        putl(dp[n]);
    }
    return 0;
}
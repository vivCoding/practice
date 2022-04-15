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
// #define LOCAL

/*
 * Problem: https://www.hackerrank.com/contests/cp1-spring-2021-topic-5/challenges/coaching-challenge/problem
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    #endif
    ll p, k; see(p, k);
    ll nums[p];
    rep(i, 0, p, 1){
        see(nums[i]);
    }
    sort(nums, nums + p);
    ll l = 0, r = nums[p - 1] - nums[0];
    ll m, ct = 0;
    while (r - l > 1) {
        m = l + (r - l) / 2;
        ll i = 2;
        ct = 0;
        while (i < p) {
            if (nums[i] - nums[i - 2] <= m) {
                ct++;
                i += 3;
            } else {
                i++;
            }
        }
        if (ct >= k) {
            r = m;
        } else {
            l = m;
        }
    }
    ll i = 2, ctl = 0, ctr = 0;
    while (i < p) {
        if (nums[i] - nums[i - 2] <= l) {
            ctl++;
            i += 3;
        } else {
            i++;
        }
    }
    i = 2;
    while (i < p) {
        if (nums[i] - nums[i - 2] <= r) {
            ctr++;
            i += 3;
        } else {
            i++;
        }
    }
    if (ctl >= k && ctr >= k) {
        if (ctl <= ctr) {
            putl(l);
        } else {
            putl(r);
        }
    } else if (ctl < k) {
        putl(r);
    } else if (ctr < k) {
        putl(l);
    }
    return 0;
}
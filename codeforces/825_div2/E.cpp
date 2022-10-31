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
    * Problem: https://codeforces.com/contest/1736/problem/E
    * UNSOLVED
*/
    
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; see(n);
    ll nums[n];
    ll mx = -1;
    int mi = -1;
    rep(i, 0, n, 1) {
        see(nums[i]);
        if (nums[i] > mx) {
            mx = nums[i];
            mi = i;
        }
    }
    ll ct = 0;
    rep(i, 0, n, 1) {
        bool change = false;
        int si = -1;
        if (i - 1 >= 0 && nums[i - 1] >= nums[i]) {
            si = i - 1;
            change = true;
        }
        if (i + 1 < n && nums[i + 1] > nums[i] && (si == -1 || nums[i + 1] > nums[si])) {
            si = i + 1;
            change = true;
        }
        if (change && si == mi) {
            swap(nums[i], nums[si]);
            nums[si] = 0;
            mi = i;
        } else if (change) {
            if (nums[si] * (mi - i - 1) + mx * 2 > nums[i] * ((mi - i) / 2) + mx * ((mi - i) / 2 + ((mi - i) % 2) + 1)) {
                swap(nums[i], nums[si]);
                nums[si] = 0;
            } else {
                swap(nums[mi], nums[mi - 1]);
                nums[mi] = 0;
                mi--;
            }
        } else if (!change && mi - 1 > 0) {
            swap(nums[mi], nums[mi - 1]);
            nums[mi] = 0;
            mi--;
        }
        ct += nums[i];
    }
    putl(ct);
    return 0;
}
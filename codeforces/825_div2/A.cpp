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
 * Problem: https://codeforces.com/contest/1736/problem/0
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; see(t);
    rep(q, 0, t, 1) {
        int n; see(n);
        int a0 = 0, a1 = 0;
        int b0 = 0, b1 = 0;
        int arr[n], arr2[n];
        rep(i, 0, n, 1) {
            see(arr[i]);
            if (arr[i] == 1) a1++;
            else a0++;
        }
        int diffs = 0;
        rep(i, 0, n, 1) {
            see(arr2[i]);
            if (arr2[i] != arr[i]) diffs++;
            if (arr2[i] == 1) b1++;
            else b0++;
        }
        if (diffs == 0) putl(0);
        else if (a0 == b0) putl(1);
        else {
            if (max(b0, b1) - min(b0, b1) > max(a0, a1) - min(a0, a1)) {
                if (b0 > b1) {
                    putl(min(diffs, b0 - a0 + 1));
                } else {
                    putl(min(diffs, b1 - a1 + 1));
                }
            } else {
                if (a0 > a1) {
                    putl(min(diffs, a0 - b0 + 1));
                } else {
                    putl(min(diffs, a1 - b1 + 1));
                }
            }
        }
    }
    return 0;
}
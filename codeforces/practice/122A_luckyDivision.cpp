#include <bits/stdc++.h>
using namespace std;
template <typename... T>
void see(T&... args) { ((cin >> args), ...); }
template<typename... T>
void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
typedef unordered_map<ll, ll> umll;
#define um unordered_map;
#define vc vector;
const ll LLMAX = LONG_LONG_MAX / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://codeforces.com/problemset/problem/122/A
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll nums[] = { 4, 44, 444, 7, 77, 777, 47, 74, 447, 744, 477, 774 };
    ll n; see(n);
    for (ll num : nums) {
        if (n % num == 0) {
            putl("YES");
            return 0;
        }
    }
    putl("NO");
    return 0;
}
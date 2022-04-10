#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll LLMAX = INT64_MAX / 2;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://codeforces.com/problemset/problem/805/B
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    string s = "abb";
    if (n <= 3) {
        cout << s.substr(0, n) << endl;
        return 0;
    }
    for (int i = 3; i < n; i++) {
        s += s[i - 2] == 'a' ? 'b' : 'a';
    }
    cout << s << endl;
    return 0;
}
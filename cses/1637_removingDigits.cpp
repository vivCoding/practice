#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1637
*/


ll get_max_digit(ll num) {
    ll m = 0;
    while (num != 0) {
        m = max(num % 10, m);
        num = num / 10;
    }
    return m;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll ct = 0;
    while (n != 0) {
        ct++;
        n -= get_max_digit(n);
    }
    cout << ct << endl;
    return 0;
}
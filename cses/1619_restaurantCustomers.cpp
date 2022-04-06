#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1619
 * UNSOLVED
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll a, b;
    vector<pll> times;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        times.push_back({ b, a });
    }
    sort(times.begin(), times.end());
    ll ct = 1;
    ll maxCt = -1;
    ll lastIdx = 0;
    for (int i = 1; i < n; i++) {
        
    }
    cout << (maxCt == -1 ? ct : maxCt) << endl;
    return 0;
}
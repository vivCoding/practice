#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/2162
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    bool cd[n];
    fill(cd, cd + n, true);
    ll i = 1;
    ll ct = n;
    while (cd[i]) {
        cout << i + 1 << " ";
        cd[i] = false;
        ct--;
        if (ct == 0) break;
        while (!cd[i]) {
            i = i == n - 1 ? 0 : i + 1;
        }
        do {
            i = i == n - 1 ? 0 : i + 1;
        } while (!cd[i]);
    }
    return 0;
}
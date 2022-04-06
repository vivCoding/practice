#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://purdue.kattis.com/sessions/oy5cet/problems/freeweights
 * UNSOLVED
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll rack[2][n];
    ll temp;
    for (int i = 0; i < 2; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> temp;
            rack[i][j] = temp;
        }
    }

    return 0;
}
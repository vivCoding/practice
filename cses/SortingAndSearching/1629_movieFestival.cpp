#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1629
*/

ll maxCt;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll a, b;
    vector<pll> movies;
    unordered_map<ll, ll> mpa, mpb;
    for (ll i = 0; i < n; i++) {
        cin >> a >> b;
        movies.push_back({ b, a });
    }
    sort(movies.begin(), movies.end());
    ll ct = 1;
    ll last = movies[0].first;
    for (ll i = 1; i < movies.size(); i++) {
        if (movies[i].second >= last) {
            ct++;
            last = movies[i].first;
        }
    }
    cout << ct << endl;
    return 0;
}
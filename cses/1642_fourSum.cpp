#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1642
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, x; cin >> n >> x;
    multimap<ll, pll> mp;
    ll nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        for (int j = 0; j < i; j++) {
            if (i != j) {
                ll sum = nums[i] + nums[j];
                mp.insert({ sum, { i, j }});
            }
        }
    }
    auto mi = mp.begin();
    auto mj = mp.rbegin();
    ll i = 0, j = mp.size() - 1;
    while (i < j) {
        ll sum = mi->first + mj->first;
        if (sum == x) {
            ll a = mi->second.first, b = mi->second.second, c = mj->second.first, d = mj->second.second;
            if (!(a == b || a == c || a == d || b == c || b == d || c == d)) {
                cout << mi->second.first + 1 << " ";
                cout << mi->second.second + 1 << " ";
                cout << mj->second.first + 1 << " ";
                cout << mj->second.second + 1 << endl;
                return 0;
            }
        }
        if (sum < x) {
            i++;
            mi++;
        } else {
            j--;
            mj++;  
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
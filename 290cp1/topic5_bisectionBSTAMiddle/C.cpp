#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://purdue.kattis.com/sessions/oy5cet/problems/monk
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll a, d; cin >> a >> d;
    ll th = 0, tt = 0;
    ll temp1, temp2;
    vector<pll> w1, w2;
    for (ll i = 0; i < a; i++) {
        cin >> temp1 >> temp2;
        th += temp1;
        tt += temp2;
        w1.push_back({ temp1, temp2 });
    }
    for (ll i = 0; i < d; i++) {
        cin >> temp1 >> temp2;
        w2.push_back({ temp1, temp2 });
    }
    ld l = 1e-7, r = tt, mid = 0;
    while (r - l > 1e-7) {
        mid = l + (r - l) / 2.0;

        ld ah = 0.0, dh = th;
        ld at = mid, dt = mid;
        for (ll i = 0; i < a; i++) {
            ah += min((ld) w1[i].first, (ld) at / w1[i].second * w1[i].first);
            at -= w1[i].second;
            if (at <= 0) break;
        }
        for (ll i = 0; i < d; i++) {
            dh -= min((ld) w2[i].first, (ld) dt / w2[i].second * w2[i].first);
            dt -= w2[i].second;
            if (dt <= 0) break;
        }
        if (ah < dh) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << setprecision(10) << r << endl;
    return 0;
}
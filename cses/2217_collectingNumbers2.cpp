#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/2217
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n, m; cin >> n >> m;
    ll nums[n];
    ll looking[n];
    ll pos[n];
    ll temp, temp2;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        temp--;
        nums[i] = temp;
        looking[temp] = 0;
        pos[temp] = i;
        if (temp + 1 < n) {
            looking[temp + 1] = 1;
        }
    }
    ll rounds = 1;
    for (ll l : looking) {
        rounds += l;
    }
    vector<pll> ops;
    for (int i =0; i < m; i++) {
        cin >> temp >> temp2;
        ops.push_back({ temp, temp2 });
    }
    for (pll op : ops) {
        ll a = op.first - 1;
        ll b = op.second - 1;
        ll n1 = nums[a];
        ll n2 = nums[b];

        bool ga = n1 == n - 1 ? true : pos[n1] < pos[n1 + 1];
        bool gb = n2 == n - 1 ? true : pos[n2] < pos[n2 + 1];
        bool gap = n1 == 0 ? true : pos[n1 - 1] < pos[n1];
        bool gbp = n2 == 0 ? true : pos[n2 - 1] < pos[n2];

        swap(pos[n1], pos[n2]);
        swap(nums[a], nums[b]);

        bool aga = n1 == n - 1 ? true : pos[n1] < pos[n1 + 1];
        bool agb = n2 == n - 1 ? true : pos[n2] < pos[n2 + 1];
        bool agap = n1 == 0 ? true : pos[n1 - 1] < pos[n1];
        bool agbp = n2 == 0 ? true : pos[n2 - 1] < pos[n2];

        if (abs(n1 - n2) == 1) {
            if ((!ga && aga) || (!gb && agb)) {
                rounds--;
            }
            if ((ga && !aga) || (gb && !agb)) {
                rounds++;
            }
            if (n1 > n2) {
                if (!gbp && agbp) {
                    rounds--;
                }
                if (gbp && !agbp) {
                    rounds++;
                }
            } else {
                if (!gap && agap) {
                    rounds--;
                }
                if (gap && !agap) {
                    rounds++;
                }
            }
        } else {
            if (!ga && aga) {
                rounds--;
            }
            if (ga && !aga) {
                rounds++;
            }
            if (!gap && agap) {
                rounds--;
            }
            if (gap && !agap) {
                rounds++;
            }
            if (!gb && agb) {
                rounds--;
            }
            if (gb && !agb) {
                rounds++;
            }
            if (!gbp && agbp) {
                rounds--;
            }
            if (gbp && !agbp) {
                rounds++;
            }
        }
        cout << rounds << endl;
    }
    return 0;
}
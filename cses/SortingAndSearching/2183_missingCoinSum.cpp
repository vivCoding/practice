#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/2183
 * understand?
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums, nums + n);
    ll ps = 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] > ps) {
            cout << ps << endl;
            return 0;
        }
        ps += nums[i];
    }
    cout << ps << endl;
    return 0;
}
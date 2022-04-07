#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1141
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n; cin >> n;
    ll nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    ll i = 0, j = 1;
    unordered_set<ll> st;
    st.reserve(n);
    st.insert(nums[0]);
    ll maxCt = 1;
    while (true) {
        if (j >= n) break;
        if (st.find(nums[j]) == st.end()) {
            st.insert(nums[j]);
            j++;
        } else {
            while (st.find(nums[j]) != st.end() && i != j) {
                st.erase(nums[i]);
                i++;
            }
            st.insert(nums[j]);
            j++;
        }
        maxCt = max((ll) st.size(), maxCt);
    }
    cout << maxCt << endl;
    return 0;
}
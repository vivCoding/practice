#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<ll> vll;
const ll MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1163
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll x, n; cin >> x >> n;
    multiset<ll> st;
    st.insert(x);
    map<ll, ll> mp;
    mp.insert({ 0, x });
    mp.insert({ x, 0 });
    ll pos;
    for (int i = 0; i < n; i++) {
        cin >> pos;
        auto p = mp.lower_bound(pos);
        p--;
        st.erase(st.find(p->second));
        ll split = p->first + p->second - pos;
        ll newL = pos - p->first;
        mp.insert({ pos, split });
        p->second = newL;
        st.insert(split);
        st.insert(newL);
        cout << *(st.rbegin()) << " ";
    }
    return 0;
}
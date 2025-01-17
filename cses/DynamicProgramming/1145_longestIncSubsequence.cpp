#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://cses.fi/problemset/task/1145
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int x;
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        cin >> x;
        int p = lower_bound(v.begin(), v.end(), x) - v.begin();
        // cout << "got " << lower_bound(v.begin(), v.end(), x) << ", " << v.begin() << endl;
        if (p == v.size()) {
            v.push_back(x);
        } else {
            v[p] = x;
        }

        for (int x : v) {
            cout << x << ", ";
        }
        cout << endl;
    }
    cout << v.size() << endl;
    return 0;
}
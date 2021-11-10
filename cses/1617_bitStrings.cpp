#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1617
*/

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    int x = 1;
    for (int i = 0; i < n; i++) {
        x *= 2;
        x %= 1000000007;
    }
    cout << x << endl;
    return 0;
}
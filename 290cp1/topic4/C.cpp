#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://purdue.kattis.com/sessions/rz5q7h/problems/roompainting
 */

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n);
    int temp, wasted = 0;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        wasted += *lower_bound(s, s + n, temp) - temp;
    }
    cout << wasted;
    return 0;
}
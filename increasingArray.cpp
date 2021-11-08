#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1094
*/

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    int prev;
    cin >> prev;
    int count = 0;
    int temp;
    for (int i = 1; i < n; i++) {
        cin >> temp;
        if (temp < prev) {
            count += prev - temp;
        } else prev = temp;
    }
    cout << count << endl;;
    return 0;
}
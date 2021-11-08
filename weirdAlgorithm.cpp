#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1068
*/

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    cout << n << " ";
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
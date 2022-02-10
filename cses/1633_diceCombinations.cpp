#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://cses.fi/problemset/task/1633
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int arr[n + 1];
    arr[0] = 1;
    for (int i = 1; i <= n; i++) {
        arr[i] = 0;
        int low = max((int) 0, i - 6);
        for (int j = low; j < i; j++) {
            arr[i] += arr[j] % MOD9;
        }
    }
    cout << arr[n] % MOD9 << endl;
    return 0;
}
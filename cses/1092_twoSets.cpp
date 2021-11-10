#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1092
*/

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    if (n * (n + 1) / 2 % 2 != 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int i = 1, j = n, target = n * (n + 1) / 4, sum = 0;
    while (sum < target) {
        if (sum + j <= target) {
            sum += j;
            j--;
        }
        if (sum + i <= target) {
            sum += i;
            i++;
        }
    }
    cout << i + n - j - 1 << endl;
    for (int x = 1; x < i; x++) {
        cout << x << " ";
    }
    for (int x = j + 1; x <= n; x++) {
        cout << x << " ";
    }
    cout << endl;
    cout << j - i + 1 << endl;
    for (int x = i; x <= j; x++) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
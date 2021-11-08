#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1070
*/

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    int p[n] = {0};
    int next = 0;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return 0;
    } else if (n == 4) {
        cout << "2 4 1 3" << endl;
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        while (p[next] != 0) next++;
        p[next] = i;
        next += 2;
        if (next >= n) {
            next = next - n;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}
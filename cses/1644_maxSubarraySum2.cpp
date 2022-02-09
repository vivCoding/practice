#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://cses.fi/problemset/task/1644
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b; cin >> n >> a >> b;
    int arr[n + 1];
    arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    
    multiset<int> ms;
    int m = -1e18;
    for (int i = a; i <= n; i++) {
        if (i > b) ms.erase(ms.find(arr[i - b - 1]));
        ms.insert(arr[i - a]);
        m = max(m, arr[i] - *ms.begin());
    }
    cout << m << endl;
    return 0;
}
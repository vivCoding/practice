#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1641
*/

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    int n, x; cin >> n >> x;
    map<int, int> m;
    int numbers[n];
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        int diff = x - numbers[i];
        for (int j = 0; j < i; j++) {
            int diff2 = diff - numbers[j]; 
            if (m.find(diff2) != m.end() && m.find(diff2)->second != j) {
                cout << i + 1 << " " << j + 1 << " " << m.find(diff2)->second + 1 << endl;
                return 0;
            }
        }
        m.insert(pair<int, int>(numbers[i], i));
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
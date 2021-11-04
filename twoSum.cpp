#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://cses.fi/problemset/task/1640
*/

int main() {
    int n, x; cin >> n >> x;
    map<int, int> m;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (m.find(x - temp) != m.end()) {
            cout << m.find(x - temp)->second << " " << i + 1 << endl;
            return 0;
        } else {
            m.insert(pair<int, int>(temp, i + 1));
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
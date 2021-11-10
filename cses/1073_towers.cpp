#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1073
*/

signed main() {
    int n; cin >> n;
    multiset<int> cubes;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        auto u = cubes.upper_bound(temp);
        if (u != cubes.end()) {
            cubes.erase(u);
        }
        cubes.insert(temp);
    }
    cout << cubes.size() << endl;
    return 0;
}
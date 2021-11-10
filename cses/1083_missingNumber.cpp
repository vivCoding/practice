#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1083
*/

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    multiset<int> numbers;
    for (int i = 0; i < n; i++) {
        numbers.insert(i + 1);
    }
    int temp;
    for (int i = 0; i < n - 1; i++) {
        cin >> temp;
        numbers.erase(temp);
    }
    cout << *numbers.begin() << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://cses.fi/problemset/task/1091
*/

int main() {
    int n, m; cin >> n >> m;
    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        tickets.insert(temp);
    }
    for (int i = 0; i < m; i++) {
        int price;
        cin >> price;
        auto up = tickets.upper_bound(price);
        if (up == tickets.begin()) {
            cout << -1 << endl;
        } else {
            cout << *(--up) << endl;
            tickets.erase(up);
        }
    }
    return 0;
}
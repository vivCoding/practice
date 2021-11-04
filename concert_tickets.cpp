#include <iostream>
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
        // int l = 0, r =  tickets.size() - 1;
        // while (r - l > 1) {
        //     int middle = (r - l) / 2 + l;
        //     int ticket = tickets.at(middle);
        //     if (ticket < price) {
        //         l = middle;
        //     } else {
        //         r = middle;
        //     }
        // }
        // int tl = tickets.at(l), tr = tickets.at(r);
        // if ((max(tl, tr) == tl && tl <= price) || tr > price) {
        //     cout << tl << endl;
        //     tickets.erase(tickets.begin() + l);
        // } else {
        //     cout << tr << endl;
        //     tickets.erase(tickets.begin() + r);
        // }
    }
    return 0;
}
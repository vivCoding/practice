#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://cses.fi/problemset/task/1091
 * UNSOLVED. needs better runtime complexity then mlog(n)
*/

int main() {
    int n, m; cin >> n >> m;
    vector<int> tickets;
    int prices[m];
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        tickets.push_back(temp);
    }
    for (int i = 0; i < m; i++) {
        cin >> prices[i];
    }
    sort(tickets.begin(), tickets.end());
    for (int price : prices) {
        if (tickets.size() == 0 || price < tickets.at(0)) {
            cout << -1 << endl;
            continue;
        }
        int l = 0, r =  tickets.size() - 1;
        while (r - l > 1) {
            int middle = (r - l) / 2 + l;
            int ticket = tickets.at(middle);
            if (ticket < price) {
                l = middle;
            } else {
                r = middle;
            }
        }
        int tl = tickets.at(l), tr = tickets.at(r);
        if ((max(tl, tr) == tl && tl <= price) || tr > price) {
            cout << tl << endl;
            tickets.erase(tickets.begin() + l);
        } else {
            cout << tr << endl;
            tickets.erase(tickets.begin() + r);
        }
    }
    return 0;
}
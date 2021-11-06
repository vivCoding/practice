#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/2216
*/

signed main() {
    int n; cin >> n;
    int looking[n] = {0};
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        temp--;
        looking[temp] = 0;
        if (temp + 1 < n) {
            looking[temp + 1] = 1;
        }
    }
    int count = 1;
    for (int l : looking) {
        count += l;
    }
    cout << count << endl;
    return 0;
}
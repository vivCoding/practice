#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://cses.fi/problemset/task/1076
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int arr[n];
    multiset<int> ms1;
    multiset<int> ms2;
    int m = k / 2 - (k % 2 == 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i < k) {
            ms2.insert(arr[i]);
        }
    }

    for (int i = 0; i <= m; i++) {
        ms1.insert(*ms2.begin());
        ms2.erase(ms2.begin());
    }

    for (int i = k; i < n; i++) {
        int med = *ms1.rbegin(); 
        cout << *ms1.rbegin() << " ";
        int last = arr[i - k];
        if (last <= *ms1.rbegin()) {
            ms1.erase(ms1.find(last));
        } else {
            ms2.erase(ms2.find(last));
        }

        if (arr[i] <= med) {
            ms1.insert(arr[i]);
        } else {
            ms2.insert(arr[i]);
        }

        while (ms1.size() < m + 1) {
            ms1.insert(*ms2.begin());
            ms2.erase(ms2.begin());
        }
        while (ms1.size() > m + 1) {
            ms2.insert(*ms1.rbegin());
            ms1.erase(prev(ms1.end()));
        }

        // for (auto p = ms1.begin(); p != ms1.end(); p++) cout << *p << ", ";
        // cout << "||| ";
        // for (auto p = ms2.begin(); p != ms2.end(); p++) cout << *p << ", ";
        // cout << endl;
    }
    cout << *ms1.rbegin() << endl;


    return 0;
}
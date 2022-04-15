#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://cses.fi/problemset/task/1077
 */

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    bool odd = k % 2 == 1;
    int arr[n];
    multiset<int> ms1;
    multiset<int> ms2;
    int m = k / 2 - (k % 2 == 0);
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i < k) {
            ms2.insert(arr[i]);
            s2 += arr[i];
        }
    }

    for (int i = 0; i <= m; i++) {
        s1 += *ms2.begin();
        ms1.insert(*ms2.begin());
        s2 -= *ms2.begin();
        ms2.erase(ms2.begin());
    }
    if (odd) s1 -= *ms1.rbegin();

    for (int i = k; i < n; i++) {
        int med = *ms1.rbegin();
        cout << s2 - s1 << " ";
        if (odd) s1 += med;
        int last = arr[i - k];
        if (last <= *ms1.rbegin()) {
            s1 -= last;
            ms1.erase(ms1.find(last));
        } else {
            s2 -= last;
            ms2.erase(ms2.find(last));
        }

        if (arr[i] <= med) {
            s1 += arr[i];
            ms1.insert(arr[i]);
        } else {
            s2 += arr[i];
            ms2.insert(arr[i]);
        }

        while (ms1.size() < m + 1) {
            s1 += *ms2.begin();
            ms1.insert(*ms2.begin());
            s2 -= *ms2.begin();
            ms2.erase(ms2.begin());
        }
        while (ms1.size() > m + 1) {
            s2 += *ms1.rbegin();
            ms2.insert(*ms1.rbegin());
            s1 -= *ms1.rbegin();
            ms1.erase(prev(ms1.end()));
        }
        if (odd) s1 -= *ms1.rbegin();

        // for (auto p = ms1.begin(); p != ms1.end(); p++) cout << *p << ", ";
        // cout << "||| ";
        // for (auto p = ms2.begin(); p != ms2.end(); p++) cout << *p << ", ";
        // cout << ": " << s1 << ", " << s2 << endl;
    }
    cout << s2 - s1 << endl;

    return 0;
}
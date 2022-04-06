#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/opkrkx/problems/airconditioned
*/

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    pair<int, int> arr[n];
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n, comp);
    int y = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i].first > y) {
            count++;
            y = arr[i].second;
        }
    }
    cout << count;
    return 0;
}
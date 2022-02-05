#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/kyafd6/problems/distinctivecharacter
 * UNSOLVED realizing they're asking about something else
 */

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    pair<int, int> arr[k];
    string temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int j = 0; j < k; j++) {
            arr[j].first += temp[j] == '0';
            arr[j].second += temp[j] == '1';
        }
    }
    for (int i = 0; i < k; i++) {
        cout << (arr[i].first > arr[i].second);
    }
    return 0;
}
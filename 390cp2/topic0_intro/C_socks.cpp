#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/yn5g3i/problems/color
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c, k; cin >> n >> c >> k;
    int socks[n];
    for (int i = 0; i < n; i++) {
        cin >> socks[i];
    }
    sort(socks, socks + n);
    int ct = 1, currentCt = 0;
    for (int i = 0; i < n - 1; i++) {
        currentCt++;
        if (currentCt == c) {
            ct++;
            currentCt = 0;
        } else if (abs(socks[i] - socks[i + 1]) > k) {
            ct++;
            currentCt = 0;
        }
    }
    if (currentCt == c) {
        ct++;
    }
    cout << ct << endl;
    return 0;
}
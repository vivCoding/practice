#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://purdue.kattis.com/courses/CS390-CP2/2023-spring/assignments/yn5g3i/problems/bungeebuilder
*/

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int heights[n];
    int ml[n], mr[n];
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        mx = max(mx, heights[i]);
        ml[i] = mx;
    }
    mx = 0;
    for (int j = n - 1; j >= 0; j--) {
        mx = max(mx, heights[j]);
        mr[j] = mx;
    }
    mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(min(ml[i], mr[i]) - heights[i], mx);
    }
    cout << mx << endl;
    return 0;
}
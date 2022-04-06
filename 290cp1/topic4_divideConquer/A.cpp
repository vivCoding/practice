#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://purdue.kattis.com/sessions/rz5q7h/problems/firefly
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, h; cin >> n >> h;
    int sg[h] = {0};
    int st[h] = {0};
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (i % 2 == 0) sg[temp - 1]++;
        else st[h - temp]++;
    }
    for (int i = h - 2; i >= 0; i--) {
        sg[i] += sg[i + 1];
    }
    for (int i = 1; i < h; i++) {
        st[i] += st[i - 1];
    }
    int mos = INT32_MAX, levels = 0;
    for (int i = 0; i < h; i++) {
        if (sg[i] + st[i] < mos) {
            mos = sg[i] + st[i];
            levels = 1;
        } else if (sg[i] + st[i] == mos) {
            levels++;
        }
    }
    cout << mos << " " << levels;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/zfo7ia/problems/rectanglesurrounding
*/

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int _  = 0; _ < 10; _++) {
        int n; cin >> n;
        if (n == 0) return 0;
        int sum = 0;
        int m[501][501] = {0};
        int minX = 500, maxX = 0, minY = 500, maxY = 0;
        for (int i = 0; i < n; i++) {
            int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
            minX = min(minX, min(x1, x2));
            maxX = max(maxX, max(x1, x2));
            minY = min(minY, min(y1, y2));
            maxY = max(maxY, max(y1, y2));
            for (int x = x1; x < x2; x++) { 
                for (int y = y1; y < y2; y++) {
                    m[x][y] = 1;
                }
            }
        }
        int count = 0;
        for (int x = minX; x < maxX; x++) {
            for (int y = minY; y < maxY; y++) {
                if (m[x][y] == 1) count++;
            }
        }
        cout << count << '\n';
    }
    return 0;
}
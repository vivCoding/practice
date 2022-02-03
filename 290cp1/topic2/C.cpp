#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/tyxded/problems/musicalchairs
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> x;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        x.push_back(pair<int, int>(temp, i));
    }
    int s = 0;
    while (n != 1) {
        s = (s + x.at(s).first - 1) % n;
        s = s <= -1 ? n - 1 : s;
        x.erase(x.begin() + s);
        n--;
        s = s > n - 1 ? 0 : s;
    }
    cout << x.front().second + 1;
    return 0;
}

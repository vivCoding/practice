#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1069
*/

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    int maxLength = 0, currentLength;
    char current = '.';
    string str;
    cin >> str;
    for (char c : str) {
        if (c != current) {
            currentLength = 1;
            current = c;
        } else currentLength++;
        maxLength = max(currentLength, maxLength);
    }
    cout << maxLength << endl;
    return 0;
}
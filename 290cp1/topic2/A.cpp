#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/tyxded/problems/paintings
*/


signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int n; cin >> n;
        vector<string> colors;
        map<string, string> avoid;
        string line;
        getline(cin, line);
        getline(cin, line);
        for (int i = 0; i < n; i++) {
            int space = line.find(' ');
            string color = line.substr(0, space);
            colors.push_back(color);
            line = line.substr(space + 1);
        }
        cin >> n;
        getline(cin, line);
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            int space = line.find(' ');
            string c1 = line.substr(0, space);
            string c2 = line.substr(space + 1);
            avoid.insert(pair<string, string>(c1, c2));
            avoid.insert(pair<string, string>(c2, c1));
        }

    }
    return 0;
}
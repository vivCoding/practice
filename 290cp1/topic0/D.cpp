#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/zfo7ia/problems/imagedecoding
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int _ = 0; _ < 10; _++) {
        int n; cin >> n;
        if (n == 0) return 0;
        else if (_ >= 1) cout << '\n';
        vector<int> lines[n];
        // eat up the new line after n
        string temp; getline(cin, temp);
        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            int length = line.length();
            int x = 0;
            while (x < length) {
                string val = line.substr(0, line.find(' '));
                if (val == "#" || val == ".") lines[i].push_back((int) val[0]);
                else {
                    lines[i].push_back(stoi(val));
                }
                x += val.length() + 1;
                line = line.substr(line.find(' ') + 1);
            }
        }
        int lineLength = -1;
        bool error = false;
        for (int i = 0; i < n; i++) {
            char c = (char) lines[i].at(0);
            auto start = lines[i].begin() + 1;
            auto end = lines[i].end();
            int sum = 0;
            for (auto p = start; p != end; p++) {
                sum += *p;
                for (int x = 0; x < *p; x++) {
                    cout << c;
                }
                c = c == '#' ? '.' : '#';
            }
            cout << '\n';
            if (lineLength == -1) lineLength = sum;
            else if (lineLength != sum) error = true;
        }
        if (error) cout << "Error decoding image\n";
    }
    return 0;
}
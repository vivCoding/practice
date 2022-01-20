#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/mntfqu/problems/restaurant
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int t = 0; t < 50; t++) {
		int n; cin >> n;
		if (n == 0) break;
		else if (t != 0) cout << '\n';
		int a = 0, b = 0;
		string line;
		// eat up \n after n
		getline(cin, line);
		for (int i = 0; i < n; i++) {
			getline(cin, line);
			string cmd = line.substr(0, line.find(' '));
			int m = stoi(line.substr(line.find(' ') + 1));
			if (cmd == "DROP") {
				a += m;
				cout << "DROP 1 " << m << '\n';
			} else {
				if (b != 0 && m > b) {
					m -= b;
					cout << "TAKE 2 " << b << '\n';
					b = 0;
				}
				if (b == 0) {
					b += a;
					a = 0;
					cout << "MOVE 1->2 " << b << '\n';
				}
				b -= m;
				cout << "TAKE 2 " << m << '\n';
			}
		}
	}
    return 0;
}
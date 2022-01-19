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
		int a = 0, b = 0;
		bool on_a = true;
		string line;
		vector<int> passes;
		// eat up \n after n
		getline(cin, line);
		for (int i = 0; i < n; i++) {
			getline(cin, line);
			string cmd = line.substr(0, line.find(' '));
			int m = stoi(line.substr(line.find(' ') + 1));
			if (cmd == "DROP") {
				passes.push_back(m);
				if (on_a) a += m; else b += m;
				cout << "DROP " << (on_a ? 1 : 2) << ' ' << m << '\n';
			} else {
				
			}
		}
	}
    return 0;
}
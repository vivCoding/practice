#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/zfo7ia/problems/joinstrings
 * UNSOLVED, runtime error after first few test cases
*/

void print(int start, vector<vector<int>> m, string* s) {
	auto ps = m.at(start);
	cout << s[start];
	for (auto p = ps.begin(); p != ps.end(); p++) {
		print(*p, m, s);
	}
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s[n];
	vector<vector<int>> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		vector<int> m2;
		m.push_back(m2);
	}
	int last = -1;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		auto pb = m.at(b - 1);
		m.at(a - 1).push_back(b - 1);
		last = a - 1;
	}
	print(last, m, s);
    return 0;
}
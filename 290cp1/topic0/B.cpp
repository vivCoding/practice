#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/zfo7ia/problems/joinstrings
*/

void print(int start, vector<int>* m, string* s, int n) {
	auto ps = m[start];
	cout << s[start];
	for (auto p = ps.begin(); p != ps.end(); p++) {
		print(*p, m, s, n);
	}
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s[n];
	vector<int> m[n];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		m[i] = vector<int>();
	}
	int last = 0;
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		m[a].push_back(b);
		last = a;
	}
	print(last, m, s, n);
    return 0;
}
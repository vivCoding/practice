#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/mntfqu/problems/dyslectionary
*/

bool comp(string a, string b) {
	int x = 1;
	while (x <= a.length() && x <= b.length()) {
		char ac = a[a.length() - x];
		char bc = b[b.length() - x];
		if (ac != bc) {
			return ac < bc;
		}
		else x++;
	}
	return a.length() < b.length();
}

void print_group(vector<string> group) {
	int length = 0;
	for (auto p = group.begin(); p != group.end(); p++) {
		length = max(length, (int) p->length());
	}
	for (auto p = group.begin(); p != group.end(); p++) {
		for (int i = p->length(); i < length; i++) {
			cout << " ";
		}
		cout << *p << '\n';
	}
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<vector<string>> groups;
	for (int t = 0; t < 100; t++) {
		vector<string> group;
		string word;
		getline(cin, word);
		if (word == "0") break;
		while (word != "") {
			group.push_back(word);
			getline(cin, word);
		}
		if (group.size() != 0) groups.push_back(group);
	}
	for (auto p = groups.begin(); p != groups.end(); p++) {
		vector<string> group = *p;
		sort(group.begin(), group.end(), comp);
		print_group(group);
		if (p != groups.end() - 1) cout << '\n';
	}
    return 0;
}
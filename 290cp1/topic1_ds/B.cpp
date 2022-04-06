#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/mntfqu/problems/baloni
*/

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	unordered_map<int, int> map;
	int temp = 0;
	int COUNT = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (map.find(temp + 1) == map.end()) {
			if (map.find(temp) != map.end()) {
				map.find(temp)->second++;
			} else map.insert(pair<int, int>(temp, 1));
			COUNT++;
		} else {
			if (map.find(temp + 1)->second == 1) {
				map.erase(temp + 1);
			} else map.find(temp + 1)->second--;
			if (map.find(temp) != map.end()) {
				map.find(temp)->second++;
			} else map.insert(pair<int, int>(temp, 1));
		}
	}
	cout << COUNT;
    return 0;
}
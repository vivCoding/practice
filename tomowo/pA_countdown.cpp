#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://vjudge.net/contest/470649#problem/A
*/

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); 
	int n, s; cin >> n >> s;
	int indices[n];
	for (int i = 0; i < n; i++) {
		cin >> indices[i];
	}
	int left = 0, right = 10;
	while (true) {
		int curr = 0;
		int mid = (right - left) / 2 + left;
		for (int i = 0; i < n; i++) {
			curr += max(mid - indices[i], (long) 0);
		}
		if (curr < s) {
			left = mid;
		} else if (curr > s) {
			right = mid;
		} else {
			cout << mid << endl;
			return 0;
		}
		if (left == right) {
			left = right;
			right *= 2;
		}
	}
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://cses.fi/problemset/task/1621
*/

int main() {
	int n;
	cin >> n;
	int x[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	sort(x, x + n);

	int count = 1;

	for (int i = 0; i < n - 1; i++) {
		if (x[i] != x[i + 1]) {
			count++;
		}
	}

	cout << count << endl;
	return 0;
}
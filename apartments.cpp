#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://cses.fi/problemset/task/1084
*/

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int tenants[n], apartments[m];
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		tenants[i] = temp;
	}
	for (int i = 0; i < m; i++) {
		cin >> temp;
		apartments[i] = temp;
	}

	sort(tenants, tenants + n);
	sort(apartments, apartments + m);

	int count = 0;
	int j = 0;
	for (int tenant : tenants) {
		if (j >= m) break;
		while (tenant - apartments[j] > k) {
			j++;
			if (j >= m) {
				cout << count << endl;
				return 0;
			}
		}
		if (abs(tenant - apartments[j]) <= k) {
			count++;
			j++;
		}
	}

	cout << count << endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
 
/*
 * Problem: https://cses.fi/problemset/task/1074
*/
 
signed main() {
	int n; cin >> n;
	int sticks[n];
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> sticks[i];
	}
	sort(sticks, sticks + n);
	int m = sticks[n / 2];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += abs(m - sticks[i]);
	}
	cout << sum << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
 * Problem: https://cses.fi/problemset/task/1643
*/

signed main() {
    int n; cin >> n;
	int temp;
	cin >> temp;
	int current_sum = temp, max_sum = temp;
	for (int i = 1; i < n; i++) {
		cin >> temp;
		current_sum = max(current_sum + temp, temp);
		max_sum = max(max_sum, current_sum);
	}
	cout << max_sum << endl;
    return 0;
}
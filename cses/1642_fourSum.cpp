#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1642
 * UNSOLVED
*/

// signed main() {
// 	ios::sync_with_stdio(false); cin.tie(nullptr);
// 	int n, x; cin >> n >> x;
// 	unordered_map<int, int> m1;
// 	int numbers[n];
// 	for (int i = 0; i < n; i++) {
// 		cin >> numbers[i];
// 		m1.insert(pair<int, int>(numbers[i], i));
// 	}

// 	unordered_map<int, pair<int, int>> m2;
// 	for (auto p = m1.begin(); p != m1.end(); p++) {
// 		for (int i = 0; i < n; i++) {
// 			// pair<int, int> x = pair<int, int>(p->second, i);
// 		}
// 		// m2.insert(pair<int, pair<int, int>)
// 	}

//     cout << "IMPOSSIBLE" << endl;
//     return 0;
// }

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, x; cin >> n >> x;
	unordered_map<int, int> m;
	int numbers[n];
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
		for (int j = 0; j < i; j++) {
			for (int k = j + 1; k < i; k++) {
				int diff = x - numbers[i] - numbers[j] - numbers[k];
				auto p = m.find(diff);
				if (p != m.end() && p->second != j && p->second != k) {
					cout << i + 1 << " " << j + 1 << " " << k + 1 << " " << p->second + 1 << endl;
					return 0;
				}
			}
		}
		m.insert(pair<int, int>(numbers[i], i));
	}
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
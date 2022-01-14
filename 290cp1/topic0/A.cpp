#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

/*
 * Problem: https://purdue.kattis.com/sessions/zfo7ia/problems/estimatingtheareaofacircle
*/


signed main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 1000; i++) {
		double r, m, c; cin >> r >> m >> c;
		if (r == 0 && m == 0 && c == 0) return 0;
		double trueArea = M_PI * pow(r, (double) 2);
		double estimatedArea = r * ((double) 2) * r * ((double) 2) * (c / m);
		cout << setprecision(1000) << trueArea << " " << estimatedArea << "\n";
	}
    return 0;
}
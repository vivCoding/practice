#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1624
*/
char board[8][8];

int solve();

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			board[x][y] = getchar();
		}
	}
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 8; y++) {

		}
	}
    return 0;
}
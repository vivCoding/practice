#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/1631
*/

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    int n; cin >> n;
    pair<int, int> books[n];
    int totalTime = 0;
    for (int i = 0; i < n; i++) {
        cin >> books[i].first;
        books[i].second = i;
        totalTime += books[i].first;
    }
    sort(books, books + n);

    pair<int, int> max = books[n - 1];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + books[i].first >= max.first && books[i].second == max.second) {
            totalTime += max.first - sum;
            break;
        } else if (sum + books[i].first >= max.first) {
            break;
        } else sum += books[i].first;
    }
    cout << totalTime << endl;
    return 0;
}
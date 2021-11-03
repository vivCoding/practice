#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://cses.fi/problemset/task/1090
*/

int main() {
    int n, x;
    cin >> n >> x;
    int weights[n];
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    sort(weights, weights + n);
    int count = 0;
    int i = 0, j = n - 1;
    bool checked[n] = {};
    while (i < j) {
        if (weights[i] + weights[j] > x) {
            j--;
        } else {
            checked[i] = checked[j] = true;
            count++;
            i++;
            j--;
        }
    }
    for (bool check : checked) {
        if (!check) count++;
    }
    cout << count << endl;
    return 0;
}
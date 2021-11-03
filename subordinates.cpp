#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://cses.fi/problemset/task/1674
*/

int count_subordinates(int bossIndex, vector<int> tree[], int counts[]) {
    int count = tree[bossIndex].size();
    for (int subordinate : tree[bossIndex]) {
        count += count_subordinates(subordinate, tree, counts);
    }
    counts[bossIndex] = count;
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<int> tree[n];
    for (int i = 2; i <= n; i++) {
        int temp;
        cin >> temp;
        tree[temp - 1].push_back(i - 1);
    }
    int counts[n] = {};
    count_subordinates(0, tree, counts);
    for (int count : counts) {
        cout << count << " ";
    }
    cout << endl;
    return 0;
}
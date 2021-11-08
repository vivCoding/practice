#include <bits/stdc++.h>
using namespace std;
#define int long

/*
 * Problem: https://cses.fi/problemset/task/2217
 * UNSOLVED
*/

signed main() {
    int n, m; cin >> n >> m;
    int nums[n];    
    int looking[n] = {0};
    int nextStuff[n];
    int prevStuff[n];
    fill(nextStuff, nextStuff + n, -1);
    fill(prevStuff, prevStuff + n, -1);
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        temp--;
        nums[i] = temp;
        looking[temp] = 0;
        if (temp + 1 < n) {
            looking[temp + 1] = 1;
            prevStuff[temp + 1] = i;
        }
        if (temp != 0) {
            nextStuff[temp - 1] = i;
        }
    }
    int count = 1;
    for (int l : looking) {
        count += l;
    }
    int t, t2;
    int x, x2;
    for (int i = 0; i < m; i++) {
        cin >> t >> t2;
        t--; t2--;
        x = nums[t], x2 = nums[t2];
        if (x != 0) {
            nextStuff[x - 1] = t2;
        }
        if (x2 != 0) {
            nextStuff[x2 - 1] = t;
        }
        if (x + 1 < n) {
            prevStuff[x + 1] = t2;
        }
        if (x2 + 1 < n) {
            prevStuff[x2 + 1] = t;
        }

        for (int next : nextStuff) {
            cout << next << ", ";
        }
        cout << endl;
        for (int prev : prevStuff) {
            cout << prev << ", ";
        }
        cout << endl << "------" << endl;
        
        swap(nums[t], nums[t2]);

        if (t2 <= nextStuff[x] && t >= nextStuff[x]) {
            count--;
            cout << 'a' << endl;
        } else if (t2 >= nextStuff[x] && t <= nextStuff[x]) {
            cout << 'b' << endl;
            count++;
        }
        
        if (t <= nextStuff[x2] && t2 >= nextStuff[x]) {
            cout << 'c' << endl;
            count--;
        } else if (t >= nextStuff[x2] && t2 <= nextStuff[x2]) {
            cout << 'd' << endl;
            count++;
        }
        
        if (t2 >= prevStuff[x] && t <= prevStuff[x]) {
            cout << 'e' << " " << x << ", " << x2  << ", " << nums[prevStuff[x]] << endl;
            count--;
        } else if (t2 <= prevStuff[x] && t >= prevStuff[x]) {
            cout << 'f' << endl;
            count++;
        }

        if (t >= prevStuff[x2] && t2 <= prevStuff[x2]) {
            cout << 'g' << endl;
            count--;
        } else if (t <= prevStuff[x2] && t2 >= prevStuff[x2]) {
            cout << 'h' << endl;
            count++;
        }

        cout << "count: " << count << endl;
    }
    return 0;
}
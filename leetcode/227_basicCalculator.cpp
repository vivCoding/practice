#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://leetcode.com/problems/basic-calculator-ii/
 */

class Solution {
public:
    int calculate(string s) {
        vector<string> sc;
        string currNum = "";
        int temp;
        bool willMd = false, dividing = false;
        for (char c : s) {
            if (c == ' ') continue;
            if (c == '+' || c == '-') {
                if (willMd) {
                    int res = dividing ? temp / stoi(currNum) : temp * stoi(currNum);
                    sc.push_back(to_string(res));
                    temp = res;
                    willMd = false;
                } else {
                    temp = stoi(currNum);
                    sc.push_back(currNum);
                }
                currNum = "";
                sc.push_back(string(&c, 1));
            }
            else if (c == '/' || c == '*') {
                if (willMd) {
                    int res = dividing ? temp / stoi(currNum) : temp * stoi(currNum);
                    temp = res;
                    willMd = false;
                } else {
                    temp = stoi(currNum);
                }
                currNum = "";
                willMd = true;
                dividing = c == '/';
            }
            else {
                currNum += c;
            }
        }
        if (willMd) {
            int res = dividing ? temp / stoi(currNum) : temp * stoi(currNum);
            sc.push_back(to_string(res));
        } else {
            sc.push_back(currNum);
        }
        // for (string str : sc) {
        //     cout << str << ", ";
        // }
        cout << endl;
        int res = stoi(sc[0]);
        for (int i = 1; i < sc.size(); i += 2) {
            if (sc[i] == "+") {
                res += stoi(sc[i + 1]);
            } else {
                res -= stoi(sc[i + 1]);
            }
        }
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    cout << Solution().calculate(s) << endl;
}

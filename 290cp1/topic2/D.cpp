#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/tyxded/problems/dobra
 */

string VOWELS = "AEIOU";
string CONSONANTS = "BCDFGHJKLMNPQRSTVWXYZ";
int length = 0;
vector<int> us;
int total = 0;

void rec(int* cv, int usi, bool hl) {
    if (usi == us.size()) {
        if (hl) {
            total++;
        }
    } else {
        int idx = us.at(usi);
        if (usi == us.size() - 1 && !hl
            && !(
                (idx > 0 && cv[idx - 1] == 0 && idx < length - 1 && cv[idx + 1] == 0)
                || ((idx == 0 || cv[idx - 1] == 1) && (idx < length - 2 && cv[idx + 1] == 0 && cv[idx + 2] == 0))
                || ((idx == length - 1 || cv[idx + 1] || cv[idx + 1] == -1) == 1 && (idx > 1 && cv[idx - 1] == 0 && cv[idx - 2] == 0))
            )
        ) {
            cv[idx] = 0;
            rec(cv, usi + 1, true);
            cv[idx] = -1;
        } else if ((usi == us.size() - 1 && hl) || usi < us.size() - 1) {
            if (!(
                (idx > 0 && cv[idx - 1] == 1 && idx < length - 1 && cv[idx + 1] == 1)
                || ((idx == 0 || cv[idx - 1] == 0) && (idx < length - 2 && cv[idx + 1] == 1 && cv[idx + 2] == 1))
                || ((idx == length - 1 || cv[idx + 1] == 0 || cv[idx + 1] == -1) && (idx > 1 && cv[idx - 1] == 1 && cv[idx - 2] == 1))
            )) {
                cv[idx] = 1;
                int curr = total;
                rec(cv, usi + 1, hl);
                total = curr + (total - curr) * 5;
                cv[idx] = -1;
            }
            if (!(
                (idx > 0 && cv[idx - 1] == 0 && idx < length - 1 && cv[idx + 1] == 0)
                || ((idx == 0 || cv[idx - 1] == 1) && (idx < length - 2 && cv[idx + 1] == 0 && cv[idx + 2] == 0))
                || ((idx == length - 1 || cv[idx + 1]  || cv[idx + 1] == -1) == 1 && (idx > 1 && cv[idx - 1] == 0 && cv[idx - 2] == 0))
            )) {
                cv[idx] = 0;
                if (!hl) {
                    rec(cv, usi + 1, true);
                } else {
                    rec(cv, usi + 1, hl);
                }
                int curr = total;
                rec(cv, usi + 1, hl);
                total = curr + (total - curr) * 20;
                cv[idx] = -1;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str; getline(cin, str);
    length = str.length();
    int cv[length];
    bool hl = false;
    for (int i = 0; i < length; i++) {
        cv[i] = str[i] == '_' ? -1 : VOWELS.find(str[i]) != -1;
        if (str[i] == '_') us.push_back(i);
        if (str[i] == 'L') hl = true;
    }
    if (us.empty()) {
        for (int i = 1; i < length - 1; i++) {
            if (cv[i - 1] == cv[i] && cv[i] == cv[i + 1]) {
                cout << 0;
                return 0;
            }
        }
    }
    rec(cv, 0, hl);
    cout << total;
    return 0;
}
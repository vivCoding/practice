#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/tyxded/problems/dobra
 * UNSOLVED
 */

string VOWELS = "AEIOU";
string CONSONANTS = "BCDFGHJKLMNPQRSTVWXYZ";
int length = 0;
vector<int> us;
int total = 0;

bool isVowel(char c) {
    return VOWELS.find(c) != -1;
}

void rec(string str, int cv[100], int usi, bool hl) {
    if (usi == us.size()) {
        // if (hl) {
            int start = max((int) 1, us.front());
            int end = min(us.back(), (int) length - 2);
            for (int i = start; i <= end; i++) {
                if (
                    (cv[i] == 1 && cv[i - 1] == 1 && cv[i + 1] == 1)
                    || (cv[i] == 0 && cv[i - 1] == 0 && cv[i + 1] == 0)
                ) {
                    return;
                }
            }
            total++;
        // }
    } else {
        int idx = us.at(usi);
        if (usi == us.size() - 1 && !hl
            && !(
                (idx > 0 && cv[idx - 1] == 0 && idx < length - 1 && cv[idx + 1] == 0)
                || ((idx == 0 || cv[idx - 1] == 1) && (idx < length - 2 && cv[idx + 1] == 0 && cv[idx + 2] == 0))
                || ((idx == length - 1 || cv[idx + 1]) == 1 && (idx > 1 && cv[idx - 1] == 0 && cv[idx - 2] == 0))
            )
        ) {
            str[idx] = 'L';
            cv[idx] = 0;
            rec(str, cv, usi + 1, true);
            cv[idx] = -1;
        } else if ((usi == us.size() - 1 && hl) || usi < us.size() - 1) {
            if (!
                ((idx > 0 && cv[idx - 1] == 1 && idx < length - 1 && cv[idx + 1] == 1)
                || ((idx == 0 || cv[idx - 1] == 0) && (idx < length - 2 && cv[idx + 1] == 1 && cv[idx + 2] == 1))
                || ((idx == length - 1 || cv[idx + 1] == 0) && (idx > 1 && cv[idx - 1] == 1 && cv[idx - 2] == 1)))
            ) {
                for (char letter : VOWELS) {
                    str[idx] = letter;
                    cv[idx] = 1;
                    rec(str, cv, usi + 1, hl);
                    cv[idx] = -1;
                }
            }
            if (!(
                (idx > 0 && cv[idx - 1] == 0 && idx < length - 1 && cv[idx + 1] == 0)
                || ((idx == 0 || cv[idx - 1] == 1) && (idx < length - 2 && cv[idx + 1] == 0 && cv[idx + 2] == 0))
                || ((idx == length - 1 || cv[idx + 1]) == 1 && (idx > 1 && cv[idx - 1] == 0 && cv[idx - 2] == 0))
            )) {
                for (char letter : CONSONANTS) {
                    str[idx] = letter;
                    cv[idx] = 0;
                    if (letter == 'L' && !hl) {
                        rec(str, cv, usi + 1, true);
                    } else {
                        rec(str, cv, usi + 1, hl);
                    }
                    cv[idx] = -1;
                }
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
        cv[i] = str[i] == '_' ? -1 : isVowel(str[i]);
        if (str[i] == '_') us.push_back(i);
        if (str[i] == 'L') hl = true;
    }
    rec(str, cv, 0, hl);
    cout << total;
    return 0;
}
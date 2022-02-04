#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * Problem: https://purdue.kattis.com/sessions/tyxded/problems/paintings
*/
int total = 0;
bool hasFav = false;
vector<string> fav;

void rec(list<string> colors, unordered_map<string, unordered_set<string>>* avoid, vector<string>* current) {
    if (colors.empty()) {
        total++;
        if (!hasFav) {
            fav = *current;
            hasFav = true;
        }
        return;
    }
    auto p = colors.begin();
    while (p != colors.end()) {
        string color = *p;
        auto it = p;
        it++;
        colors.erase(p);
        if (current->size() == 0) {
            current->push_back(color);
            rec(colors, avoid, current);
            current->pop_back();
        } else {
            auto pa = avoid->find(current->back());
            if (pa == avoid->end() || pa->second.find(color) == pa->second.end()) {
                current->push_back(color);
                rec(colors, avoid, current);
                current->pop_back();
            }
        }
        colors.insert(it, color);
        p = it;
    }
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    for (int ti = 0; ti < t; ti++) {
        int n; cin >> n;
        list<string> colors = list<string>();
        string line;
        getline(cin, line);
        getline(cin, line);
        for (int i = 0; i < n; i++) {
            int space = line.find(' ');
            string color = line.substr(0, space);
            colors.push_back(color);
            line = line.substr(space + 1);
        }
        int an; cin >> an;
        unordered_map<string, unordered_set<string>> avoid = unordered_map<string, unordered_set<string>>(an);
        getline(cin, line);
        for (int i = 0; i < an; i++) {
            getline(cin, line);
            int space = line.find(' ');
            string c1 = line.substr(0, space);
            string c2 = line.substr(space + 1);
            auto p1 = avoid.find(c1);
            if (p1 != avoid.end()) {
                p1->second.insert(c2);
            } else avoid.insert(pair<string, unordered_set<string>>(c1, unordered_set<string>({c2})));
            auto p2 = avoid.find(c2);
            if (p2 != avoid.end()) {
                p2->second.insert(c1);
            } else avoid.insert(pair<string, unordered_set<string>>(c2, unordered_set<string>({c1})));
        }
        total = 0;
        vector<string> c;
        hasFav = false;
        rec(colors, &avoid, &c);
        cout << total << endl;
        for (auto p = fav.begin(); p != fav.end() - 1; p++) {
            if (*p == "") continue;
            cout << *p << " ";
        }
        cout << fav.back();
        if (ti < t - 1) cout << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<string> words;
string target;
unordered_map<int, bool> mp;

bool dfs(int idx) {
    if (mp[idx]) return false;
    for (string w : words) {
        if (idx + w.length() > target.length()) {
            continue;
        }
        bool good = true;
        for (int i = 0; i < w.length(); i++) {
            if (target[idx + i] != w[i]) {
                good = false;
                break;
            }
        }
        if (good) {
            if (idx + w.length() == target.length()) return true;
            if (dfs(idx + w.length())) return true;
        }
    }
    mp[idx] = true;
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    target = s;
    words.insert(words.end(), wordDict.begin(), wordDict.end());
    return dfs(0);
}

int main() {
    // string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    // vector<string> v = {
    //     "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa",
    //     "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"
    // };
    string s = "cars";
    vector<string> v = { "car", "ca", "rs" };
    cout << wordBreak(s, v) << endl;
    return 0;
}
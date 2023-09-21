#include <bits/stdc++.h>
using namespace std;

vector<string> words;
string target;
unordered_map<int, vector<string>> mp;
vector<string> res;


void dfs(string curr, int idx, int lastIdx) {
    bool good = false;
    for (string w : words) {
        if (idx + w.length() > target.length()) {
            continue;
        }
        string sw = target.substr(idx, w.length());
        if (sw != w) {
            continue;
        }
        string x = curr + (idx != 0 ? " " : "") + w;
        if (idx + w.length() == target.length()) {
            res.push_back(x);
        }
        // dfs(x, idx + w.length(), )
    }
}

void dfs(string curr, int idx) {
    if (mp[idx]) return;
    bool good = false;
    for (string w : words) {
        if (idx + w.length() > target.length()) {
            continue;
        }
        bool good2 = true;
        for (int i = 0; i < w.length(); i++) {
            if (target[idx + i] != w[i]) {
                good2 = false;
                break;
            }
        }
        if (good2) {
            string x = curr + (idx != 0 ? " " : "") + w;
            if (idx + w.length() == target.length()) {
                res.push_back(x);
                good = true;
            }
            dfs(x, idx + w.length());
        }
    }
    if (!good) {
        mp[idx] = true;
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    target = s;
    words.insert(words.end(), wordDict.begin(), wordDict.end());
    dfs("", 0);
    return res;
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
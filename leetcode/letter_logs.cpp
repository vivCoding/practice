#include <bits/stdc++.h>
using namespace std;

bool sort(string s, string s1) {
    
}

vector<string> reorderLogFiles(vector<string>& logs) {
    vector<string> letterLogs, digiLogs;
    for (string log : logs) {
        string s = log;
        vector<string> words;
        bool first = false, digits = false;
        while (true) {
            int x = s.find(' ');
            if (x != -1) {
                if (!first) {
                    // for ())
                    words.push_back(s.substr(0, x));
                    s = s.substr(x + 1);
                } else first = true;
            } else {
                words.push_back(s);
                break;
            }
        }
        bool isDigit = false;
        
    }
    sort(logs.begin(), logs.end());
    return logs;
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    res.push_back("()");
    vector<string> curr; 
    for (int i = 1; i < n; i++) {
        curr.clear();
        for (int i = 0; i < res.size(); i++) {
            curr.push_back("(" + res[i] + ")");
            curr.push_back("()" + res[i]);
            if (i != res.size() - 1) {
                curr.push_back(res[i] + "()");
            }
        }
        res.clear();
        res = curr;
    }
    return res;
}
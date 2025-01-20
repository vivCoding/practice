#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/word-ladder/description/
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited(wordList.size());
        queue<string> q;
        q.push(beginWord);
        int ct = 1;
        int stepsTaken = 1;
        while (!q.empty()) {
            string currWord = q.front();
            q.pop();
            visited.insert(currWord);
            ct--;
            for (string word : wordList) {
                if (visited.find(word) != visited.end()) continue;
                // ensure word is only one char diff
                bool differsOne = false;
                bool good = true;
                for (int i = 0; i < beginWord.size(); i++) {
                    if (currWord[i] != word[i]) {
                        if (differsOne) {
                            good = false;
                            break;
                        } else {
                            differsOne = true;
                        }
                    }
                }
                if (!good) continue;

                if (word == endWord) {
                    return stepsTaken + 1; 
                }
                q.push(word);
                visited.insert(word);
            }
            if (ct == 0) {
                ct = q.size();
                stepsTaken++;
            }
        }
        return 0;
    }

    // move efficient
    int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int ct = 1;
        int stepsTaken = 1;
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            ct--;
            // try every transformation
            for (int i = 0; i < word.length(); i++) {
                char orig = word[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if (wordSet.find(word) != wordSet.end()) {
                        if (word == endWord) return stepsTaken + 1;
                        wordSet.erase(word);
                        q.push(word);
                    }
                }
                word[i] = orig;
            }
            if (ct == 0) {
                ct = q.size();
                stepsTaken++;
            }
        }
        return 0;
    }
};
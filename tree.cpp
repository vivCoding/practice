#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// use map to store tree
unordered_map<char, pair<char, char>> tree;
// keeps track of which nodes have parents and how many. Helps to find root(s) and possible cycles
unordered_map<char, int> numParents;
// will represent final s-expression
string s = "";

void createSE(char root) {
    s += "(";
    s += root;
    if (tree.find(root) != tree.end()) {
        if (tree[root].second != 0) {
            if (tree[root].first < tree[root].second) {
                createSE(tree[root].first);
                createSE(tree[root].second);
            } else {
                createSE(tree[root].second);
                createSE(tree[root].first);
            }
        } else createSE(tree[root].first);
    }
    s += ")";
}

int main() {
    string temp; getline(cin, temp);
    // if empty, nothing to be done
    if (temp == "") {
        cout << endl;
        return 0;
    }
    // parse input and attempt to create tree
    while (true) {
        // ensure we have parentheses, comma, and single values
        int open = temp.find('('), close = temp.find(')');
        if (open != 0 || close != 4 || close - open != 4 || (temp.length() >= 2 && temp[2] != ',')) {
            cout << "E1" << endl;
            return 0;
        }
        string pair = temp.substr(open, close + 1);
        char parent = pair[1], child = pair[3];
        // ensure values are capital letters
        if (ALPHABET.find(parent) != -1 && ALPHABET.find(child) != -1) {
            // add to tree, ensure no duplicates or multiple children
            if (tree.find(parent) == tree.end()) {
                tree[parent] = {child, 0};
            } else if (tree[parent].second == 0 && child != tree[parent].first) {
                tree[parent].second = child;
            } else {
                // figure out if duplicate or multiple children to return correct error
                if (child == tree[parent].first || child == tree[parent].second) {
                    cout << "E2" << endl;
                } else {
                    cout << "E3" << endl;
                }
                return 0;
            }
            // update number of parents child has
            numParents[child]++;
            // avoid resetting parent's count
            if (numParents.find(parent) == numParents.end()) {
                numParents[parent] = 0;
            }
        } else {
            cout << "E1" << endl;
            return 0;
        }

        // if closing bracket is at end, we're done parsing
        if (close == temp.length() - 1) break;
        temp = temp.substr(close + 2);
    }

    // Figure out if we have multiple roots (e.g. num of parents = 0)
    // At the same time, figure out if we have cycles
    // Prioritize returning error for multiple roots over cycle error
    char root = 0;
    bool cycles = false;
    for (auto p : numParents) {
        if (p.second == 0) {
            if (root != 0) {
                cout << "E4" << endl;        
                return 0;
            }
            root = p.first;
        }
        if (p.second > 1) cycles = true;
    }
    if (cycles || root == 0) {
        cout << "E5" << endl;
        return 0;
    }
    createSE(root);
    cout << s << endl;
    return 0;
}
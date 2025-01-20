#include <bits/stdc++.h>
using namespace std;
const long long MOD9 = 1e9 + 7;

/*
 * Problem: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                if (token == "+") st.push(left + right);
                if (token == "-") st.push(left - right);
                if (token == "*") st.push(left * right);
                if (token == "/") st.push(left / right);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};
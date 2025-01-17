#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/implement-queue-using-stacks/
*/

class MyQueue {
public:
    stack<int> mainSt;
    stack<int> tempSt;

    MyQueue() {
        
    }
    
    void push(int x) {
        mainSt.push(x);
    }
    
    int pop() {
        if (!tempSt.empty()) {
            int front = tempSt.top();
            tempSt.pop();
            return front;
        }
        while (!mainSt.empty()) {
            tempSt.push(mainSt.top());
            mainSt.pop();
        }
        int front = tempSt.top();
        tempSt.pop();
        return front;
    }
    
    int peek() {
        if (!tempSt.empty()) {
            int front = tempSt.top();
            return front;
        }
        while (!mainSt.empty()) {
            tempSt.push(mainSt.top());
            mainSt.pop();
        }
        return tempSt.top();
    }
    
    bool empty() {
        return tempSt.empty() && mainSt.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
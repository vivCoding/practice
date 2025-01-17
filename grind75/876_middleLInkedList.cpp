#include <bits/stdc++.h>
using namespace std;

/*
 * Problem: https://leetcode.com/problems/middle-of-the-linked-list/
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head) return NULL;
        ListNode* h1 = head;
        ListNode* h2 = head;
        while (h2->next) {
            if (h1->next) {
                h1 = h1->next;
            }
            if (h2->next && h2->next->next) {
                h2 = h2->next->next;
            } else {
                return h1;
            }
        }
        return h1;
    }
};
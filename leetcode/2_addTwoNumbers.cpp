#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD9 = 1000000007;

/*
 * Problem: https://leetcode.com/problems/add-two-numbers/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int remainder = 0;
        ListNode* head = NULL;
        ListNode* current = NULL;
        ListNode* lp = l1;
        ListNode* lp2 = l2;
        while (lp != NULL || lp2 != NULL) {
            int sum = (lp ? lp->val : 0) + (lp2 ? lp2->val : 0) + remainder;
            remainder = sum / 10;
            sum = sum % 10;
            if (current == NULL) {
                current = new ListNode(sum);
                head = current;
            } else {
                current->next = new ListNode(sum);
                current = current->next;
            }
            lp = lp ? lp->next : NULL;
            lp2 = lp2 ? lp2->next : NULL;
        }
        if (remainder) {
            current->next = new ListNode(remainder);
        }
        return head;
    }
};
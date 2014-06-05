// You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        int carry = 0, sum = 0;
        ListNode *head = NULL, *prev = NULL;
        while(l1 && l2) {
            int a = l1->val, b = l2->val;
            sum = a+b+carry;
            ListNode *newNode = new ListNode(sum%10);
            if(!head) head = newNode;
            if(prev) prev->next = newNode;
            prev = newNode;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *l3 = l1 ? l1 : l2;
        while(l3) {
            int a = l3->val;
            sum = a + carry;
            ListNode *newNode = new ListNode(sum%10);
            prev->next = newNode;
            prev = newNode;
            carry = sum/10;
            l3 = l3->next;
        }
        if(carry) {
            prev->next = new ListNode(1);
        }
        return head;
    }
};

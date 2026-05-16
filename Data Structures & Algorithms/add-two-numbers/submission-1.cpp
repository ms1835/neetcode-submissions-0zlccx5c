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

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = dummy;
        int carry = 0, sum, digit;
        while(p1 && p2){
            sum = p1->val + p2->val + carry;
            digit = sum %10;
            carry = sum /10;
            ListNode *curr = new ListNode(digit);
            tmp->next = curr;
            tmp = tmp->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        while(p1 || p2){
            sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + carry;
            digit = sum % 10;
            carry = sum / 10;
            ListNode *curr = new ListNode(digit);
            tmp->next = curr;
            tmp = tmp->next;
            if(p1)
                p1 = p1->next;
            if(p2)
                p2 = p2->next;
        }
        if(carry > 0){
            ListNode *curr = new ListNode(carry);
            tmp->next = curr;
        }
        return dummy->next;
    }
};

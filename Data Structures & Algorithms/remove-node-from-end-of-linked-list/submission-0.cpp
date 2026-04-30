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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) return nullptr;
        int count = 0;
        ListNode *tmp = head;
        while(tmp != nullptr){
            tmp = tmp->next;
            count++;
        }
        int times = count-n;
        if(times == 0)
            return head->next;
        ListNode *prev = NULL;
        tmp = head;
        for(int i=0;i<times;i++){
            prev = tmp;
            tmp = tmp->next;
        }
        if(prev)
            prev->next = tmp->next;
        return head;
    }
};

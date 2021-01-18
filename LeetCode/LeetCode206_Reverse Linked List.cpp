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
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;
        ListNode * pre = nullptr;
        ListNode * cur = head;
        ListNode * nxt = head->next;
        while (cur && cur->next)
        {
            cur->next = pre;
            pre = cur;
            cur = nxt;
            nxt = cur->next;
        }
        cur->next = pre;
        return cur;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static auto io = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow{head};
        while (slow)
        {
            /* faster pointer */
            if (!head || !head->next)
                return false;
            head = head->next->next;
            slow = slow->next;
            if (slow == head)
                return true;
        }
        return false;
    }
    /*
    bool hasCycle(ListNode *head) {
        std::map<ListNode *, int> nd2pos;
        int pos = 0;
        while (head)
        {
            nd2pos[head] = pos++;
            head = head->next;
            if (nd2pos.count(head))
            {
                std::cout << "Position: " << nd2pos[head] << " (val: " << head->val << ")" << std::endl;
                return true;
            }
        }
        return false;
    }
    */
};
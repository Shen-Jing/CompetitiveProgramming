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
    bool hasCycle(ListNode *head) {
        std::vector<ListNode *> vec;
        while (head)
        {
            vec.emplace_back(head);
            head = head->next;
            auto find_iter = std::find(vec.begin(), vec.end(), head);
            if (find_iter != vec.end())
            {
                std::cout << find_iter - vec.begin() << std::endl;
                std::cout << (*find_iter)->val;
                return true;
            }
        }
        return false;
    }
};
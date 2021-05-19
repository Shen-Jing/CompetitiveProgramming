#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <tuple>
#include <type_traits>
#include <utility>
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>
#include "utils.hpp"

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        return get_intersection_node_by_cycle(headA, headB);
    }

 private:
    ListNode *get_intersection_node_by_cycle(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;

        ListNode *tailA{headA};
        while (tailA->next)
            tailA = tailA->next;
        tailA->next = headA;  // generate a cycle

        ListNode *slow{headB}, *fast{headB}, *curr{headB}, *intersection;
        bool has_cycle = false;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                has_cycle = true;
                while (curr)
                {
                    if (curr == slow)
                    {
                        intersection = curr;
                        break;
                    }
                    slow = slow->next;
                    curr = curr->next;
                }
                break;
            }
        }
        /* Restore list (cancel cycle) */
        tailA->next = nullptr;

        if (has_cycle)
            return intersection;
        return nullptr;
    }
};

int main(void)
{

    return 0;
}
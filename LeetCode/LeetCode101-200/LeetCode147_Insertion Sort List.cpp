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
    ListNode* insertionSortList(ListNode *head)
    {
        ListNode *dummy_min = new ListNode(numeric_limits<int>::min()),
                 *dummy_max = new ListNode(numeric_limits<int>::max()),
                 *dummy = new ListNode();
        ListNode *sorted_head{dummy_min}, *prev{dummy}, *curr{head};
        dummy_min->next = dummy_max;
        dummy->next = head;

        while (curr)
        {
            ListNode *sorted_prev{sorted_head}, *sorted_iter{sorted_head};
            while (sorted_iter)
            {
                if (sorted_iter->val <= curr->val && curr->val <= sorted_iter->next->val)
                    break;
                sorted_iter = sorted_iter->next;
            }
            /* Unsorted node is removed from original (unsorted) list */
            prev->next = curr->next;
            /* Inserting unsorted node into sorted list */
            curr->next = sorted_iter->next;
            sorted_iter->next = curr;
            /* Move forward (iterator) */
            curr = prev->next;
        }
        delete dummy, dummy_min, dummy_max;
        return sorted_head->next;
    }
};

int main(void)
{

    return 0;
}
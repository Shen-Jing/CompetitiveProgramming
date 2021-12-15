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
                 *dummy_max = new ListNode(numeric_limits<int>::max());
        ListNode *sorted_head{dummy_min}, *prev, *curr{head};
        dummy_min->next = dummy_max;

        while (curr)
        {
            ListNode *sorted_prev{sorted_head}, *sorted_iter{sorted_head->next};
            while (sorted_iter && sorted_iter->val <= curr->val)
            {
                sorted_prev = sorted_iter;
                sorted_iter = sorted_iter->next;
            }
            /* Unsorted node is removed from original (unsorted) list */
            prev->next = curr->next;
            /* Inserting unsorted node into sorted list */
            sorted_prev->next = curr;
            curr->next = sorted_iter;
            /* Iterating unsorted list */
            curr = prev->next;
        }
        return sorted_head;
    }
};

int main(void)
{

    return 0;
}
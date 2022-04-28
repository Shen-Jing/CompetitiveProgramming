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
    ListNode* oddEvenList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *odd_head(head), *even_head, *odd, *even;
        odd = odd_head;
        even = even_head = odd_head->next;
        while (even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return odd_head;
    }

 private:
    /* Practice with Sean (2022-04-22) */
    ListNode *reorder(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *odd = head, *even = head->next, *even_head = head->next,
                *curr{head->next->next};
        int idx = 1;
        while (curr)
        {
            if (idx)
            {
                odd->next = curr;
                odd = odd->next;
            }
            else
            {
                even->next = curr;
                even = even->next;
            }
            curr = curr->next;
            /* ~idx: ~1 => -2 */
            idx = !idx;
        }
        odd->next = even_head;
        even->next = nullptr;
        return head;
    }
};

int main(void)
{

    return 0;
}
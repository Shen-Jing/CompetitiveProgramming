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
        ListNode dummy(0, nullptr);
        ListNode *prev = &dummy, *curr{head};

        /* Consider curr as an unsorted index/iterator */
        while (curr)
        {
            ListNode *prev{&dummy};
            while (prev->next && prev->next->val < curr->val)
            {
                prev = prev->next;
            }
            /* Inserting unsorted node into sorted list */
            ListNode *temp_next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            /* Move forward (iterator) */
            curr = temp_next;
        }
        return dummy.next;
    }
};

int main(void)
{

    return 0;
}
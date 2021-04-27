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
    ListNode* reverseList(ListNode* head)
    {
        return reverse_list_iterative(head);
    }

 private:
    ListNode* reverse_list_iterative(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *prev = nullptr, *curr = head;
        while (curr)
        {
            ListNode *tmp_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp_next;
        }
        return prev;
    }

    ListNode* reverse_list_recursive(ListNode *head)
    {
    }
};

int main(void)
{

    return 0;
}
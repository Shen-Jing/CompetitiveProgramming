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
    bool hasCycle(ListNode *head)
    {
        return check_cycle_by_hash_table(head);
        return check_cycle_by_two_pointers(head);
    }
 
 private:
    bool check_cycle_by_two_pointers(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (!fast && !fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (slow == fast)
                return true;
        }
        return false;
    }

    bool check_cycle_by_hash_table(ListNode *head)
    {
        unordered_set<ListNode *> nodes;
        while (head)
        {
            if (nodes.count(head))
                return true;
            nodes.emplace(head);
            head = head->next;
        }
        return false;
    }
};

int main(void)
{

    return 0;
}
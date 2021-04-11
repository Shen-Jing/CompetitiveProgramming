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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode *fast = head, *slow = head;
        
        for (int steps = 0; steps <= n; ++steps)
            fast = fast->next;

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *deleted = slow->next;
        slow->next = slow->next->next;

        return head;
    }
};

int main(void)
{
    ListNode *head;
    Serializer serializer;

    Solution sol;
    serializer.deserialize("1 2 3 4 5", head);
    cout << serializer.serialize(sol.removeNthFromEnd(head, 2)) << "\n";

    return 0;
}
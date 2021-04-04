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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        ListNode *result = new ListNode(), *cur = result;
        while (l1 || l2 || carry)
        {
            /* 被加數；加數 */
            int summand = (l1) ? l1->val : 0,
                addend  = (l2) ? l2->val : 0;
            summand += addend + carry;
            if (summand >= 10)
            {
                carry = 1;
                summand -= 10;
            }
            else
                carry = 0;
            cur->next = new ListNode(summand);
            cur = cur->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return result->next;
    }
};

int main(void)
{
    ListNode *l1, *l2;
    Serializer serializer;

    Solution sol;
    serializer.deserialize("2 4 3", l1);
    serializer.deserialize("5 6 4", l2);
    cout << serializer.serialize(sol.addTwoNumbers(l1, l2)) << "\n";

    serializer.deserialize("9 9 9 9 9 9 9", l1);
    serializer.deserialize("9 9 9 9", l2);
    cout << serializer.serialize(sol.addTwoNumbers(l1, l2)) << "\n";
    return 0;
}
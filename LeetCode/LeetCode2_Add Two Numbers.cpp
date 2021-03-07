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
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
 public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (!l1 && !l2)
            return nullptr;
        int carry = 0;
        ListNode *result, *cur = result;
        while (l1 || l2)
        {
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
        }
        return result->next;
    }
};

int main(void)
{

    return 0;
}
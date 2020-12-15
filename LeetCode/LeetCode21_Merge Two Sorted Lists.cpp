#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
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
 public:
  int val;
  ListNode *next;

  ListNode() : val(0), next(nullptr) {}
  ListNode(int v) : val(v), next(nullptr) {}
  ListNode(int v, ListNode *n) : val(v), next(n) {}
};

class Solution
{
 public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;

        return dummy->next;
    }

    ListNode* mergeTwoLists_recursive(ListNode* l1, ListNode* l2)
    {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        if (l1->val <= l2->val)
        {
            auto new_l1 = l1->next;
            l1->next = l2;
            return mergeTwoLists(new_l1, l2);
        }
        auto new_l1 = l1->next;
        l1->next = l2;
        return mergeTwoLists(new_l1, l2);
    }
};

int main(void)
{

    return 0;
}
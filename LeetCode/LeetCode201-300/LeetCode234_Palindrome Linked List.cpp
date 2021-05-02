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
    bool isPalindrome(ListNode* head)
    {
        return check_palindrome_by_reverse(head);
    }
  
  private:
    ListNode *get_middle_node(ListNode *head)
    {
        ListNode *slow{head}, *fast{head};
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reverse_list(ListNode *head)
    {
        ListNode *tmp_next{head};
        ListNode *prev{nullptr}, *curr{head};

        while (curr)
        {
            tmp_next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp_next;
        }
        return prev;
    }

    bool check_palindrome_by_reverse(ListNode *head)
    {
        auto *middle = get_middle_node(head);
        auto *tgt_head = reverse_list(middle);

        auto *qry_curr = head;
        auto *tgt_curr = tgt_head;
        while (tgt_curr)
        {
            if (qry_curr->val != tgt_curr->val)
                return false;
            qry_curr = qry_curr->next;
            tgt_curr = tgt_curr->next;
        }
        return true;
    }
};

int main(void)
{
    ListNode *head;
    Serializer serializer;

    Solution sol;
    serializer.deserialize("1 2 2 1", head);
    sol.isPalindrome(head);

    return 0;
}
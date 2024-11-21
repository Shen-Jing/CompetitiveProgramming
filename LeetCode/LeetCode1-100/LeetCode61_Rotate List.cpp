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
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <unordered_map>
#include <unordered_set>
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
    /* Rotate right by k steps: set (n - k + 1)th (or kth from the end) node as head */
    ListNode* rotateRight(ListNode *head, int k)
    {
        if (!head)
            return nullptr;
        /* 1. Get the list length & the tail node */
        ListNode *tail = head;
        int n = get_list_length_and_tail(head, tail);
        k = k % n;
        if (k == 0)
            return head;

        /* 2. Create link between the head & the tail */
        tail->next = head;

        /* 3. Find the (n - k + 1)th node. Set it as the new head */
        ListNode dummy(0, head);
        ListNode *curr = &dummy, *prev = nullptr;
        for (int i = 1; i <= (n - k + 1); ++i)
        {
            prev = curr;
            curr = curr->next;
        }
        
        /* 4. Set the node before the new head as the new tail */
        prev->next = nullptr;

        return curr;
    }

 private:
    int get_list_length_and_tail(ListNode *head, ListNode *&tail)
    {
        int cnt = 0;
        while (head != nullptr)
        {
            ++cnt;
            tail = head;  // store the previous node
            head = head->next;
        }
        return cnt;
    }
};

int main(void)
{

    return 0;
}
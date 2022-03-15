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
static auto io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class ListNode
{
 public:
    int value;
    ListNode *next;
    ListNode();
    ListNode(int v, ListNode *nxt = nullptr) : value(v), next(nxt) {};
};

void print_list(ListNode *head)
{
    while (head)
    {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* insert_list(ListNode *head, int inserted_value)
{
    ListNode *inserted_node = new ListNode(inserted_value);
    if (!head)
        return inserted_node;
    ListNode *curr = head;
    while (curr)
    {
        if (!curr->next)
            break;
        curr = curr->next;
    }
    curr->next = inserted_node;
    return head;
}

ListNode* reverse_list(ListNode *head)
{
    /* 1 -> 2 -> 3 
       1 <- 2 -> 3
       1 <- 2 <- 3 */
    ListNode *prev = head, *curr = head->next;
    prev->next = nullptr;
    while (prev && curr)
    {
        ListNode *nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

int find_half_max(ListNode *head)
{
    /* 1 -> 2 -> 3 
       */
    ListNode *slow = head, *fast = head;
    int max_val = head->value;
    while (fast)
    {
        max_val = max(max_val, slow->value);
        slow = slow->next;
        fast = fast->next->next;
    }
    return max_val;
}


int main(void)
{
    ListNode *head = insert_list(head, 1);
    head = insert_list(head, 2);
    head = insert_list(head, 3);
    print_list(head);
    cout << find_half_max(head);

    return 0;
}
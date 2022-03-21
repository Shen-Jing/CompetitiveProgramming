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

/* sorted 
   A = [1, 2, 6, 8]
   B = [4, 3, 5] 
   A = [1, 3, 5] 
   B = [2, 4, 6, 8]
   A = [1, 2, 3] 
   B = [4, 5, 6, 8]
   Ans = [1, 2, 3, 4, 5, 6] */
vector<int> merge_array_inplace(vector<int> &nums1, vector<int> &nums2)
{
    int sz1 = nums1.size(), sz2 = nums2.size();
    if (sz1 > sz2)
        return merge_array(nums2, nums1);
    vector<int> ans;
    ans.reserve(sz1 + sz2);
    int idx1{0}, idx2{0};
    for (; idx1 < sz1 && idx2 < sz2; )
    {
        if (nums1[idx1] <= nums2[idx2])
        {
            ++idx1;
            if (nums1[idx1] >= nums2[idx2])
                swap(nums1[idx1 + 1], nums2[idx2]);
            for (int j = idx2 + 1; j < sz2; ++j)
            {
                if (nums2[j - 1] > nums[j])
                    swap(nums2[j - 1], nums[j]);
            }
        }
        else
        {
            if (nums2[idx2 + 1] >= nums2[idx2])
                swap(nums1[idx1 + 1], nums2[idx2]);
            for (int j = idx2 + 1; j < sz2; ++j)
            {
                if (nums2[j - 1] > nums[j])
                    swap(nums2[j - 1], nums[j]);
            }
        }
    }
    for (; idx2 < sz2; ++idx2)
        ans.emplace_back(nums2[idx2]);
    return ans;
}

vector<int> merge_array(vector<int> &nums1, vector<int> &nums2)
{
    int sz1 = nums1.size(), sz2 = nums2.size();
    if (sz1 > sz2)
        return merge_array(nums2, nums1);
    vector<int> ans;
    ans.reserve(sz1 + sz2);
    int idx1{0}, idx2{0};
    for (; idx1 < sz1 && idx2 < sz2; )
    {
        if (nums1[idx1] <= nums2[idx2])
        {
            ans.emplace_back(nums1[idx1]);
            ++idx1;
        }
        else
        {
            ans.emplace_back(nums2[idx2]);
            ++idx2;
        }
    }
    for (; idx2 < sz2; ++idx2)
        ans.emplace_back(nums2[idx2]);
    return ans;
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
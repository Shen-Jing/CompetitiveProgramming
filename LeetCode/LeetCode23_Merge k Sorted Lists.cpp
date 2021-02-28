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
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
};

class Solution
{
 public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        return brute_force_merge_k_lists(lists);
        // ListNode *head;
        // int min = ;
        // for (const auto &list : lists)
        // {
        //     if 
        // }
        
    }

 private:
    ListNode* brute_force_merge_k_lists(vector<ListNode*>& lists)
    {
        vector<int> sorted_vector;
        for (auto &list : lists)
        {
            while (list)
            {
                sorted_vector.emplace_back(list->val);
                list = list->next;
            }
        }
        sort(sorted_vector.begin(), sorted_vector.end());
        ListNode *head = new ListNode(), *cur = head;
        for (const auto & val : sorted_vector)
        {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        head = head->next;
        return head;
    }
};

int main(void)
{
    Solution sol;
    vector<ListNode*> lists;
    vector<vector<int>> data{{1,4,5}, {1,3,4}, {2,6}};
    for (auto &&v : data)
    {
        ListNode *head, *cur = head;
        for (auto &&val : v)
        {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        lists.emplace_back(head->next);
    }
    sol.mergeKLists(lists);

    return 0;
}
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
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    int maximumTop(vector<int>& nums, int k)
    {
    }

 private:
    int total_moves;
    vector<int> max_values;
    int first_try_by_backtrack(vector<int>& nums, int k)
    {
        total_moves = k;
        deque<int> nums_stk;
        for (const auto &num : nums)
            nums_stk.push_back(num);
        unordered_set<int> removed;
        dfs(nums_stk, removed, 0);
        return *max_element(max_values.begin(), max_values.end());
    }

    void dfs(deque<int> &nums_stk, unordered_set<int> &removed, int curr_move)
    {
        if (curr_move == total_moves)
        {
            if (nums_stk.empty())
                max_values.emplace_back(-1);
            else
                max_values.emplace_back(nums_stk.front());
            return;
        }

        /* Pop */
        if (!nums_stk.empty())
        {
            int topmost = nums_stk.front();
            nums_stk.pop_front();
            removed.emplace(topmost);
            dfs(nums_stk, removed, curr_move + 1);
            nums_stk.push_front(topmost);
            removed.erase(topmost);
        }

        /* Add */
        unordered_set<int> old = removed;
        for (const auto &rm : old)
        {
            nums_stk.push_front(rm);
            removed.erase(rm);
            dfs(nums_stk, removed, curr_move + 1);
            nums_stk.pop_front();
            removed.emplace(rm);
        }
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums;
    
    nums = {2};
    sol.maximumTop(nums, 1);

    nums = {5,2,2,4,0,6};
    sol.maximumTop(nums, 4);

    return 0;
}
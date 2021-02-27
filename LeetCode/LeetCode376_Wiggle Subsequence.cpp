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
    int wiggleMaxLength(vector<int>& nums)
    {
        if (nums.size() < 2)
            return nums.size();
        // return recursive_wiggle_max_length(nums);
        return get_normal_dp_ans(nums);
    }

 private:
    /* 1. Brute Force */
    int recursive_wiggle_max_length(const vector<int> &nums)
    {
        return 1 + max(calculate(nums, 0, true), calculate(nums, 0, false));
    }

    /* is_up: whether we need to find an increasing wiggle or decreasing wiggle */
    int calculate(const vector<int> &nums, int index, bool is_up)
    {
        auto sz = nums.size();
        int max_count = 0;
        for (int i = index + 1; i < sz; ++i)
        {
            /* Check the current number meets the current target or not */
            if (
                (is_up  && nums[i] > nums[index]) || 
                (!is_up && nums[i] < nums[index])
               )
                max_count = max(max_count, 1 + calculate(nums, i, !is_up));
        }
        return max_count;
    }

    /* 2. Normal Dynamic Programming */
    int get_normal_dp_ans(const vector<int> &nums)
    {
        auto sz = nums.size();
        /* the max length of the current wiggle direction */
        vector<int> up(sz, 0), down(sz, 0);
        for (size_t anchor_idx = 1; anchor_idx < sz; ++anchor_idx)
        {
            for (size_t i = 0; i < anchor_idx; ++i)
            {
                if (nums[anchor_idx] > nums[i])
                    up[anchor_idx] = max(up[anchor_idx], down[i] + 1);
                else if (nums[anchor_idx] < nums[i] )
                    down[anchor_idx] = max(down[anchor_idx], up[i] + 1);
            }
        }
        return 1 + max(up[sz - 1], down[sz - 1]);
    }
};

int main(void)
{
    Solution sol;
    string input, delim{","};
    while (getline(cin, input))
    {
        vector<int> nums;
        vector<string> split_result;
        /**
        * Example: [1,7,4,9,2,5]
        * String Length: 13
        */
        input = input.substr(1, input.length() - 2);
        split(split_result, input, delim);
        for (auto &&token : split_result)
            nums.emplace_back(stoi(token));
        cout << sol.wiggleMaxLength(nums) << "\n";
    }

    return 0;
}
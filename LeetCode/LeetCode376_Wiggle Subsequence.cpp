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

class Solution
{
 public:
    int wiggleMaxLength(vector<int>& nums)
    {
        auto sz = nums.size();
        if (sz < 2)
            return sz;
        return recursive_wiggle_max_length(nums);
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
};

int main(void)
{

    return 0;
}
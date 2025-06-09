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

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    bool checkPossibility(vector<int> &nums)
    {
        return trivial_scenario_if(nums);
    }

 private:
    /// **Incorrect**
    /// Checks if the given array `nums` can be made non-decreasing by modifying at most one element.
    /// 
    /// 1. Start from the end of the array and iterate backwards.
    /// 2. Maintain the current minimum to track the smallest value encountered so far
    ///    (starting from the last element of the array).
    /// 3. If the current element is greater than the current min, it means the array
    ///    is not non-decreasing at this point.
    bool firstVersion(vector<int> &nums)
    {
        int sz = nums.size();
        int changes = 1, cur_min = nums[sz - 1];
        for (int i = sz - 2; i >= 0; --i)
        {
            if (nums[i] > cur_min)
            {
                if (--changes < 0)
                {
                    return false;
                }
            }
            else
            {
                cur_min = nums[i];
            }
        }
        return true;
    }

    /// Enumearte the scenarios previously
    bool trivial_scenario_if(vector<int> &nums)
    {
        int sz = nums.size();
        int err_cnt = 0;
        for (int i = 2; i + 1 < sz; ++i)
        {
            if (nums[i - 1] > nums[i])
            {
                if (err_cnt++ && (nums[i - 2] > nums[i] || nums[i] > nums[i + 1]))
                    return false;
            }
        }
        return true;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums;

    nums.assign({4, 3, 3});
    sol.checkPossibility(nums);

    nums.assign({5, 7, 1, 8});
    sol.checkPossibility(nums);
    return 0;
}
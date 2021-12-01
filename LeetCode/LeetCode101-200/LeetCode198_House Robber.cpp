
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

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution
{
 public:
    int rob(std::vector<int> &nums)
    {
        auto sz = nums.size();
        std::vector<std::vector<int>> dp;
        dp.emplace_back(sz, -1);
        dp.emplace_back(sz, -1);
        
        /* 
        * element: max money
        *   Row 1: Rob the current house
        *   Row 0: or not 
        */
        dp[0][0] = 0;
        dp[1][0] = nums[0];
        for (int house_idx = 0; house_idx < sz; ++house_idx)
        {
            dp[0][house_idx] = std::max(dp[0][house_idx - 1],
                                        dp[1][house_idx - 1]);
            dp[1][house_idx] = dp[0][house_idx - 1] + nums[house_idx];
        }
        return std::max(dp[0][sz - 1], dp[1][sz - 1]);
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{1, 1, 2, 3};
    sol.rob(nums);

    return 0;
}
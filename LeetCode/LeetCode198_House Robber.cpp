
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <vector>

static auto io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
  public:
      int rob(std::vector<int>& nums) {
          int sz = static_cast<int>(nums.size());
          std::vector<std::vector<int>> dp;
          dp.emplace_back(sz, -1);
          dp.emplace_back(sz, -1);
          
          /* 
           * house_idx: [][*]
           */
          for (int house_idx = 0; house_idx < sz; ++house_idx)
          {
              if (!house_idx)
              {
                  dp[0][house_idx] = 0;
                  dp[1][house_idx] = nums[house_idx];
                  continue;
              }
              else
              {
                  dp[0][house_idx] = std::max(dp[0][house_idx - 1],
                                              dp[1][house_idx - 1]);
                  dp[1][house_idx] = dp[0][house_idx - 1] + nums[house_idx];
              }
          }
          return std::max(dp[0][sz - 1], dp[1][sz - 1]);
      }
};

int main(void)
{
    Solution sol;

    return 0;
}

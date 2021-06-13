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
    bool canPartition(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1)
            return false;
        int target = sum / 2;
        return can_partition_by_bottom_up(nums, target);
        return can_partition_by_backtrack(nums, nums.size() - 1, target);
    }

 private:
    bool can_partition_by_backtrack(const vector<int> &nums, int idx, int target)
    {
        if (target < 0 || idx < 0)
            return false;
        if (target == 0)
            return true;
        return can_partition_by_backtrack(nums, idx - 1, target - nums[idx]) || can_partition_by_backtrack(nums, idx - 1, target);
    }

    bool can_partition_by_bottom_up(const vector<int> &nums, const int &target)
    {
        int sz = nums.size();
        vector<vector<bool>> dp(target + 1, vector<bool>(sz + 1, false));

        /* Init */
        for (size_t i = 0; i < sz; ++i)
        {
            if (nums[i] <= target)
                dp[nums[i]][i] = true;
            dp[0][i] = true;
        }
        dp[0][sz] = true;

        /* Build table */
        for (int t = 1; t <= target; ++t)
            for (int i = 1; i <= sz; ++i)
            {
                if (t >= nums[i - 1])
                {
                    dp[t][i] = dp[t - nums[i - 1]][i - 1] || dp[t][i - 1];
                }
            }
        return dp[target][sz];
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{1, 2, 5};
    sol.canPartition(nums);

    return 0;
}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <limits>
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
    int convertArray(vector<int> &nums)
    {

        vector<int> reversed_nums(nums.rbegin(), nums.rend());
        return min(DP(nums), DP(reversed_nums));
    }

 private:
    /// 0 <= nums[i] <= 1000
    int max_val = 1000;
    /// cost[i][j]: Adjusting the first nums[0] ~ nums[i - 1] elements to non-decreasing,
    ///             the min cost of adjusting nums[i] to the number j
    /// cost[0][j]: The cost of adjusting nums[0] to j -> abs(nums[0] - j)
    int DP(const vector<int> &nums)
    {
        int sz = nums.size();
        int min_cost = numeric_limits<int>::max();
        vector<vector<int>> costs(sz, vector<int>(max_val + 1, numeric_limits<int>::max()));

        for (int j = 0; j <= max_val; ++j)
        {
            costs[0][j] = abs(nums[0] - j);
        }
        for (int i = 1; i < sz; ++i)
        {
            for (int j = 0; j <= max_val; ++j)
            {
                /// The possible adjusted number `k`: 0 to j
                /// The current optimal value: min([i - 1][k] + abs(num[i] - j))
                for (int k = 0; k <= j; ++k)
                {
                    costs[i][j] = min(costs[i][j], costs[i - 1][k] + abs(nums[i] - k));
                    min_cost = min(min_cost, costs[i][j]);
                }
            }
        }
        return min_cost;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums;
    nums.assign({3,2,4,5,0});
    sol.convertArray(nums);
    
    return 0;
}
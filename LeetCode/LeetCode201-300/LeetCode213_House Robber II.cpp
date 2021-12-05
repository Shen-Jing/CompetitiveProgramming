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
    int rob(vector<int> &nums)
    {
        int sz = nums.size();
        max_profit.assign(sz, -1);
        return max(rob_from(nums, 0, sz - 2), rob_from(nums, 1, sz - 1));
    }

 private:
    vector<int> max_profit;
    int rob_from(const vector<int> &nums, int cur_idx, const int &end_idx)
    {
        if (cur_idx > end_idx)
            return 0;
        if (max_profit[cur_idx] != -1)
            return max_profit[cur_idx];
        return max_profit[cur_idx] = 
            max(rob_from(nums, cur_idx + 1, end_idx), 
                rob_from(nums, cur_idx + 2, end_idx) + nums[cur_idx]);
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{2, 3, 2};
    cout << sol.rob(nums) << "\n";

    nums = {1, 2, 3};
    cout << sol.rob(nums) << "\n";

    return 0;
}
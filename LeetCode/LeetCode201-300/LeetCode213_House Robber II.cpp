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
        return max(rob_from(nums, 0, sz - 1), rob_from(nums, 1, sz));
    }

 private:
    vector<int> max_profit;
    /* Range: [first, last) */
    int rob_from(const vector<int> &nums, const int &first, const int &last)
    {
        /* Bottom Up DP */
        int max_profit{0}, prev_profit, prev_prev_profit;
        prev_profit = prev_prev_profit = 0;
        for (int i = last - 1; i >= first; --i)
        {
            max_profit = max(prev_profit, nums[i] + prev_prev_profit);
            prev_prev_profit = prev_profit;
            prev_profit = max_profit;
        }
        return max_profit;
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
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
    int maxSubArray(vector<int> &nums)
    {
        return get_max_by_DP(nums);
    }

 private:
    int brute_force(vector<int> &nums)
    {
        const auto sz = nums.size();

        /* Range: [start, end] */
        int max_subarray_sum = numeric_limits<int>::min();
        for (size_t start = 0; start < sz; ++start)
        {
            int cur_subarray_sum{0};
            for (size_t end = start; end < sz; ++end)
            {
                cur_subarray_sum += nums[end];
                max_subarray_sum = max(max_subarray_sum, cur_subarray_sum);
            }
        }
        return max_subarray_sum;
    }

    /* Kadane's Algorithm */
    int get_max_by_DP(vector<int> &nums)
    {
        auto sz = nums.size();
        int max_sum, cur_sum;
        max_sum = cur_sum = nums[0];
        for (int i = 1; i < sz; ++i)
        {
            cur_sum = max(cur_sum + nums[i], nums[i]);
            max_sum = max(max_sum, cur_sum);
        }
        return max_sum;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sol.maxSubArray(nums) << "\n";

    return 0;
}
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
    int maxSubArray(vector<int>& nums)
    {
        const auto sz = nums.size();

        /* Range: [start, end] */
        int max_sum = numeric_limits<int>::min();
        int cur_sum = 0;
        for (size_t i = 0; i < sz; ++i)
        {
            cur_sum += nums[i];
            max_sum = max(max_sum, cur_sum);
            if (cur_sum < 0)
                cur_sum = 0;
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
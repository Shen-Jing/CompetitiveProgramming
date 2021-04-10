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
        vector<vector<int>> max_range_sum(sz, vector<int>(sz, 0));

        /* Range: [start, end] */
        int max_sum = numeric_limits<int>::min();
        for (size_t start = 0; start < sz; ++start)
        {
            for (size_t end = start; end < sz; ++end)
            {
                max_range_sum[start][end] = 
                                    (start == end) 
                                    ? nums[start]
                                    : max_range_sum[start][end] = max_range_sum[start][end - 1] + nums[end];
                max_sum = max(max_sum, max_range_sum[start][end]);
            }
        }
        return max_sum;
    }
};

int main(void)
{

    return 0;
}
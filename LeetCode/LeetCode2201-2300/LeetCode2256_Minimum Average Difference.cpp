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
    int minimumAverageDifference(vector<int> &nums)
    {
        int sz = nums.size();
        vector<long long> prefix_sum(sz, 0);
        
        // int total_sum = accumulate(nums.begin(), nums.end(), 0);
        prefix_sum[0] = nums[0];
        for (int i = 1; i < sz; ++i)
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        
        long long min_avg_diff = numeric_limits<int>::max(), min_idx{0};
        for (int i = 0; i < sz; ++i)
        {
            long long first_part = prefix_sum[i] / (i + 1),
                last_part = (i == sz - 1) ? 0 : (prefix_sum[sz - 1] - prefix_sum[i]) / (sz - i - 1);
            long long cur_diff = abs(first_part - last_part);
            if (cur_diff < min_avg_diff)
            {
                min_avg_diff = cur_diff;
                min_idx = i;
            }
        }
        return min_idx;
    }
};

int main(void)
{

    return 0;
}
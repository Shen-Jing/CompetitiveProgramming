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
    int subarraySum(vector<int> &nums, int k)
    {
        return prefix(nums, k);
    }

 private:
    int my_2D_DP(vector<int> &nums, int k)
    {
        int total{0};
        auto sz = nums.size();
        vector<vector<int>> subarray_sums(sz, vector<int>(sz, 0));

        for (int start = 0; start < sz; ++start)
            for (int end = start; end < sz; ++end)
            {
                if (start == end)
                    subarray_sums[start][end] = nums[start];
                else
                    subarray_sums[start][end] = subarray_sums[start][end - 1] + nums[end];
                
                if (subarray_sums[start][end] == k)
                    ++total;
            }

        return total;
    }

    int prefix(const vector<int> &nums, const int &k)
    {
        auto sz = nums.size();
        vector<int> prefix_sums(sz, 0);
        prefix_sums.front() = nums.front();
        for (int i = 1; i < sz; ++i)
        {
            prefix_sums[i] = prefix_sums[i - 1] + nums[i];
        }

        unordered_map<int, int> prefix_sums_cnts;
        int cnt{0};
        for (int i = 0; i < sz; ++i)
        {
            if (prefix_sums[i] == k)
                ++cnt;
            cnt += prefix_sums_cnts[prefix_sums[i] - k];
            ++prefix_sums_cnts[prefix_sums[i]];
        }
        return cnt;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{1};
    sol.subarraySum(nums, 0);  // 0

    return 0;
}
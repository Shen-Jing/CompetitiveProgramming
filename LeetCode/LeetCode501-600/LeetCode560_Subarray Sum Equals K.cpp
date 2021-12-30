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
    }

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
};

int main(void)
{

    return 0;
}
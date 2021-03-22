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
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> ans;
        auto sz = nums.size();
        
        if (sz < 3)
            return vector<vector<int>>{};
        sort(nums.begin(), nums.end());  // For a <= b <= c in (a, b, c)
        for (size_t i = 0; i <= sz - 3; ++i)
        {
            if (i && nums[i] == nums[i - 1])
                continue;
            size_t start = i + 1, last = sz - 1;
            int target = 0 - nums[i];
            while (start < last)
            {
                auto cur_value = nums[start] + nums[last];
                if (cur_value < target)
                    ++start;
                else if (cur_value > target)
                    --last;
                else 
                {
                    ans.emplace(vector<int>{nums[i], nums[start], nums[last]});
                    ++start;
                }
            }
        }
        return vector<vector<int>>{ans.begin(), ans.end()};
    }
};

int main(void)
{
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    Solution sol;
    sol.threeSum(nums);
    return 0;
}
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
#include <numeric>
#include <queue>
#include <tuple>
#include <type_traits>
#include <utility>
#include <regex>
#include <set>
#include <stack>
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
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans;
        map<int, int> value_to_index;
        auto sz = nums.size();
        for (size_t i = 0; i < sz; ++i)
        {
            int complement = target - nums[i];
            if (value_to_index.count(complement))
            {
                ans.emplace_back(i);
                ans.emplace_back(value_to_index[complement]);
                return ans;
            }
            value_to_index[nums[i]] = i;
        }
        return ans;
    }
};

int main(void)
{
    vector<int> nums{2, 7, 11, 15};
    int target{9};
    Solution sol;
    sol.twoSum(nums, target);

    return 0;
}
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
    vector<vector<int>> permute(vector<int>& nums) {
        my_permute(nums, 0);
        return ans_;
    }
 private:
    vector<vector<int>> ans_;

    void permute_STL(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        do
        {
            ans_.emplace_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
    }

    void my_permute(vector<int> &nums, size_t first)
    {
        if (first == nums.size())
            ans_.emplace_back(nums);
        else
        {
            for (size_t i = first; i < nums.size(); ++i)
            {
                swap(nums[first], nums[i]);
                my_permute(nums, first + 1);
                swap(nums[first], nums[i]);
            }
        }
    }
};
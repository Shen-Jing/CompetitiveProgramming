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
    vector<vector<int>> subsets(vector<int>& nums)
    {
        auto sz = nums.size();
        is_set.resize(sz);
        set_bits(nums, 0);
        return vector<vector<int>>{ans.begin(), ans.end()};
    }

  private:
    vector<bool> is_set;
    set<vector<int>> ans;

    void get_subset(const vector<int> &nums)
    {
        vector<int> elements;
        for (size_t i = 0; i < is_set.size(); ++i)
        {
            if (is_set[i])
                elements.emplace_back(nums[i]);
        }
        ans.emplace(elements);
    }

    void set_bits(const vector<int> &nums, size_t idx)
    {
        if (idx == nums.size())
            return;
        for ( ; idx < nums.size(); ++idx)
        {
            is_set[idx] = true;
            set_bits(nums, idx + 1);
            get_subset(nums);

            is_set[idx] = false;
            set_bits(nums, idx + 1);
            get_subset(nums);
        }
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums{1, 2, 3};
    sol.subsets(nums);
    return 0;
}
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
    void init(const vector<int> &nums)
    {
        /* Counting Sort */
        const auto &[min_it, max_it] = minmax_element(nums.begin(), nums.end());
        min_value = *min_it, max_value = *max_it;
        data_range = max_value - min_value + 1;
        prefix_sum.assign(data_range, 0);
    }

    auto counting_sort(vector<int> &nums)
    {
        for (const auto &value : nums)
            ++prefix_sum[value - min_value];
        for (int value = min_value + 1; value <= max_value; ++value)
            prefix_sum[value - min_value] += prefix_sum[value - min_value - 1];
        
        vector<int> tmp;
        tmp.resize(nums.size());
        auto sz = nums.size();
        for (int i = 0; i < data_range; ++i)  // Not stable
        {
            tmp[prefix_sum[nums[i] - min_value] - 1] = nums[i];
            --prefix_sum[nums[i]];
        }
        // swap(nums, tmp); // [ ] memory leak?
        return tmp;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        init(nums);
        return counting_sort(nums);
    }

 private:
     /* Counting Sort */
     int min_value, max_value;
     int data_range;
     vector<int> prefix_sum;
};

int main(void)
{

    Solution sol;
    vector<int> nums{3, 7, 7, 7, 10, 4, 4, 11, 11, 11, 11};
    sol.sortArray(nums);
    return 0;
}
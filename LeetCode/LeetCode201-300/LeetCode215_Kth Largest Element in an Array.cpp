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
    int findKthLargest(vector<int>& nums, int k)
    {
        auto sz = nums.size();
        return nums[get_Kth_smallest_index(nums, 0, sz - 1, sz - k + 1 - 1)];
    }

    /* Range: [first, last] 
       Notice: Ascending order, find smallest */
    int get_Kth_smallest_index(vector<int> &nums, int first, int last, int k)
    {
        if (first < last)
        {
            int pivot_pos = partition(nums, first, last);
            if (pivot_pos == k)
                return pivot_pos;
            else if (pivot_pos < k)
                return get_Kth_smallest_index(nums, pivot_pos + 1, last, k);
            else
                return get_Kth_smallest_index(nums, first, pivot_pos - 1, k);
        }
        return first;
    }
  
  private:
    /* Range: [first, last] */
    int partition(vector<int> &nums, int first, int last)
    {
        auto &pivot_value = nums[last];
        /* The last position smaller than the pivot */
        int last_smaller_idx = first - 1;
        for (int i = first; i <= last - 1; ++i)
        {
            if (nums[i] < pivot_value)
            {
                ++last_smaller_idx;
                swap(nums[last_smaller_idx], nums[i]);
            }
        }
        ++last_smaller_idx;
        swap(nums[last_smaller_idx], pivot_value);
        return last_smaller_idx;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{3,2,1,5,6,4};
    sol.findKthLargest(nums, 2);

    nums = {3,2,3,1,2,4,5,5,6};
    sol.findKthLargest(nums, 4);

    nums = {7,6,5,4,3,2,1};
    sol.findKthLargest(nums, 2);

    return 0;
}
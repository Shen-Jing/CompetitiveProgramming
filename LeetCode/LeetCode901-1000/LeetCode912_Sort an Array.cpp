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
#include <span>
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

    /**
     * @brief Insertion Sort
     * 
     * @param nums 
     * @return auto 
     */
    auto insertion_sort(vector<int> &nums)
    {
        const auto sz = nums.size();
        for (int unsorted_idx = 0; unsorted_idx < sz; ++unsorted_idx)
        {
            auto curr_unsorted_value = nums[unsorted_idx];
            int sorted_idx = unsorted_idx - 1;
            while (sorted_idx >= 0 && nums[sorted_idx] > curr_unsorted_value)
            {
                nums[sorted_idx + 1] = nums[sorted_idx];
                --sorted_idx;
            }
            nums[sorted_idx + 1] = curr_unsorted_value;
        }
        return nums;
    }

    /**
     * @brief Counting sort 
     * 
     * @param nums 
     * @return Sorted result
     */
    auto counting_sort(vector<int> &nums)
    {
        for (const auto &value : nums)
            ++prefix_sum[value - min_value];
        for (int i = 1; i < data_range; ++i)
            prefix_sum[i] += prefix_sum[i - 1];
        
        vector<int> tmp;
        tmp.resize(nums.size());
        auto sz = nums.size();
        for (int i = 0; i < sz; ++i)  // Not stable
        {
            tmp[prefix_sum[nums[i] - min_value] - 1] = nums[i];
            --prefix_sum[nums[i] - min_value];
        }
        // swap(nums, tmp); // [ ] memory leak?
        return tmp;
    }

    /**
     * @brief Merge Sort
     * 
     * @param nums 
     * @param left range start (closed)
     * @param right range end (open, not included)
     * 
     * merge_sort(nums, 0, nums.size());
     * return nums;
     */
    void merge_sort(vector<int> &nums, size_t left, size_t right)
    {
        if (right - left > 1)
        {
            auto mid = left + ((right - left) >> 1);
            merge_sort(nums, left, mid);
            merge_sort(nums, mid, right);
            merge_inplace(nums, left, right);
            // merge_by_alloc_new_sub(nums, left, right);
        }
        return;
    }

    vector<int> sortArray(vector<int> &nums)
    {
        init(nums);
    }

 private:
    /* Counting Sort */
    int min_value, max_value;
    int data_range;
    vector<int> prefix_sum;

    void merge_by_alloc_new_sub(vector<int> &nums, size_t left, size_t right)
    {
        auto mid = left + ((right - left) >> 1);
        /* Not inplace: allocate 2 new subarray */
        auto sub_left  = span(nums.begin() + left, nums.begin() + mid);
        auto sub_right = span(nums.begin() + mid, nums.begin() + right);
        // auto sub_left  = vector<int>{nums.begin() + left, nums.begin() + mid};
        // auto sub_right = vector<int>{nums.begin() + mid, nums.begin() + right};

        vector<int> tmp_out;
        tmp_out.reserve(right - left);
        size_t l_idx = 0, r_idx = 0;
        size_t l_len = mid - left, r_len = right - mid;
        while (l_idx < l_len && r_idx < r_len)
        {
            if (sub_left[l_idx] <= sub_right[r_idx])
                tmp_out.emplace_back(sub_left[l_idx++]);
            else
                tmp_out.emplace_back(sub_right[r_idx++]);
        }

        /* Only one of the following (2 loops) will be executed  */
        for ( ; l_idx < l_len; ++l_idx)
            tmp_out.emplace_back(sub_left[l_idx]);
        for ( ; r_idx < r_len; ++r_idx)
            tmp_out.emplace_back(sub_right[r_idx]);
        
        for (size_t i = left, out_idx = 0; i < right; ++i, ++out_idx)
            nums[i] = tmp_out[out_idx];
    }

    /* Range: [left, right) */
    void merge_inplace(vector<int> &nums, size_t left, size_t right)
    {
        auto mid = left + ((right - left) >> 1);

        vector<int> tmp_out;
        tmp_out.reserve(right - left);
        size_t l_idx{left}, r_idx{mid}, t_idx{0};

        while (l_idx < mid || r_idx < right)
        {
            if (r_idx >= right || (l_idx < mid && nums[l_idx] <= nums[r_idx]))
                tmp_out[t_idx++] = nums[l_idx++];
            else /* r_idx < right && (l_idx >= mid || nums[l_idx] > nums[r_idx]) */
                tmp_out[t_idx++] = nums[r_idx++];
        }

        for (size_t i{left}, out_idx{0}; out_idx < t_idx; ++i, ++out_idx)
            nums[i] = tmp_out[out_idx];
    }
};

int main(void)
{

    Solution sol;

    vector<int> nums{5, 2, 3, 1, 4};
    sol.sortArray(nums);

    nums = {5, 1, 1, 2, 0, 0};
    sol.sortArray(nums);

    return 0;
}
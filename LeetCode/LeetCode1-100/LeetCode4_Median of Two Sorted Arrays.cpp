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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        auto m = nums1.size(), n = nums2.size();
        size_t i, j;
        size_t first{0}, last{m};

        /* mid (range): [first, last] */
        while (first <= last)
        {
            auto i = first + ((last - first) >> 1);  // role: mid
            j = ((n + m) >> 1) - i;

            auto left_max_1  = (i == 0) ? numeric_limits<int>::min() : nums1[i - 1];
            auto right_min_1 = (i == m) ? numeric_limits<int>::max() : nums1[i];

            auto left_max_2 = (j == 0) ? numeric_limits<int>::min() : nums2[j - 1];
            auto right_min_2 = (j == n) ? numeric_limits<int>::max() : nums2[j];

            if (left_max_1 <= right_min_2 && left_max_2 <= right_min_1)
            {
                if ((m + n) & 1)
                    return min(right_min_1, right_min_2);
                return (max(left_max_1, left_max_2) + min(right_min_1, right_min_2)) * 0.5;
            }
            else if (left_max_1 > right_min_2)
                last = i;
            else if (right_min_1 < left_max_2)
                first = i + 1;
        }
        
        return 0;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums1{1, 3};
    vector<int> nums2{2};
    cout << sol.findMedianSortedArrays(nums1, nums2) << "\n";

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << "\n";

    return 0;
}
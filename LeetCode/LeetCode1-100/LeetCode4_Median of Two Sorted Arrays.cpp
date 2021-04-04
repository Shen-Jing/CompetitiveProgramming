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
        if (nums1.size() >= nums2.size())
            nums1.swap(nums2);
        
        auto m = nums1.size(), n = nums2.size();
        size_t i = 0, j;
        size_t first{0}, last{m};

        while (first < last)
        {
            auto mid = first + (last - first) >> 1;  // role: i
            j = (n + m) >> 1 - mid;
            if (nums1[mid] >= nums2[j - 1])
                last = mid;
            else
                first = mid + 1;
        }
        
        j = (n + m) >> 1 - first;
        if ((m + n) & 1)
            return max(nums1[first - 1], nums2[j - 1]);
        return (max(nums1[first - 1], nums2[j - 1]) + min(nums1[first], nums2[j])) / 2;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums1{1, 3};
    vector<int> nums2{2};
    sol.findMedianSortedArrays(nums1, nums2);
    return 0;
}
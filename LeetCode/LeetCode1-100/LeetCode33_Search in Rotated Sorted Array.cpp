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
    int search(vector<int> &nums, int target)
    {
        int shift = get_min_idx(nums),
            sz = nums.size();
        int first = 0, last = sz;
        while (first < last)
        {
            int mid = first + ((last - first) >> 1),
                shifted_mid = get_shifted_idx(mid, shift, sz);
            if (nums[shifted_mid] >= target)
                last = mid;
            else
                first = mid + 1;
        }
        auto shifted_first = get_shifted_idx(first, shift, sz);
        if (nums[shifted_first] == target)
            return shifted_first;
        return -1;
    }

 private:
    int shift_;
    int get_shifted_idx(const int &idx, const int &shift, const int &sz)
    {
        return (idx + shift) % sz;
    }

    /* LeetCode 153. Find Minimum in Rotated Sorted Array */
    int get_min_idx(vector<int> &nums)
    {
        return min_element(nums.begin(), nums.end()) - nums.begin();
    }
};

int main(void)
{
    Solution sol;
    /* origin: [0, 7)
       shifted: [4, 4) */
    vector<int> nums{4,5,6,7,0,1,2};

    sol.search(nums, 0);
    sol.search(nums, 3);

    return 0;
}
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
    int findMin(vector<int> &nums)
    {
        auto peak_idx = find_peak_index(nums);
        if (nums.size() == 1)
            return nums[0];
        if (peak_idx == nums.size() - 1)
            return nums.front();
        return nums[peak_idx + 1];
    }

 private:
    int find_peak_index(const vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        if (nums.front() < nums.back())
            return nums.size() - 1;

        int first = 0, last = nums.size() - 1;
        while (first < last)
        {
            int mid = first + ((last - first) >> 1);
            if (nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid] > nums[first])
                first = mid + 1;
            else
                last = mid;
        }
        return -1;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{11};
    cout << sol.findMin(nums) << endl;

    nums = {11, 13, 15, 17};
    cout << sol.findMin(nums) << endl;

    nums = {2, 1};
    cout << sol.findMin(nums) << endl;

    nums = {2, 3, 4, 5, 1};
    cout << sol.findMin(nums) << endl;

    return 0;
}
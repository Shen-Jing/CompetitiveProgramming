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
#include <unordered_map>
#include <unordered_set>
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
    int findUnsortedSubarray(vector<int> &nums)
    {
        return better_brute_force(nums);
    }

 private:
    int better_brute_force(const vector<int> &nums)
    {
        int sz = nums.size(), first_unsorted_idx = -1, last_unsorted_idx = -2;
        for (int left = 0; left < sz; ++left)
        {
            bool is_unsorted = false;
            for (int i = 0; i < left; ++i)
            {
                if (nums[i] > nums[left])
                {
                    is_unsorted = true;
                    break;
                }
            }

            for (int i = left + 1; i < sz; ++i)
            {
                if (nums[i] < nums[left])
                {
                    is_unsorted = true;
                    break;
                }
            }

            if (is_unsorted)
            {
                first_unsorted_idx = left;
                break;
            }
        }

        for (int right = sz - 1; right >= 0; --right)
        {
            bool is_unsorted = false;
            for (int i = 0; i < right; ++i)
            {
                if (nums[i] > nums[right])
                {
                    is_unsorted = true;
                    break;
                }
            }

            for (int i = right + 1; i < sz; ++i)
            {
                if (nums[i] < nums[right])
                {
                    is_unsorted = true;
                    break;
                }
            }

            if (is_unsorted)
            {
                last_unsorted_idx = right;
                break;
            }
        }
        return last_unsorted_idx - first_unsorted_idx + 1;
    }
};

int main(void)
{

    return 0;
}
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
    int countHillValley(vector<int>& nums)
    {
    }

    int first_try(vector<int>& nums)
    {
        int ans{0};
        for (int i = 1; i <= nums.size() - 2; ++i)
        {
            if (nums[i] == nums[i - 1])
                continue;
            if (is_hill(nums, i))
                ++ans;
            else if (is_valley(nums, i))
                ++ans;
        }
        return ans;
    }

 private:
    bool is_hill(const vector<int> &nums, int idx)
    {
        bool left_flag{false}, right_flag{false};
        for (int left = idx - 1; left >= 0; --left)
        {
            if (nums[left] < nums[idx])
            {
                left_flag = true;
                break;
            }
            else if (nums[left] == nums[idx])
                continue;
            else
                break;
        }
        for (int right = idx + 1; right < nums.size(); ++right)
        {
            if (nums[right] < nums[idx])
            {
                right_flag = true;
                break;
            }
            else if (nums[right] == nums[idx])
                continue;
            else
                break;
        }
        return (left_flag && right_flag);
    }

    bool is_valley(const vector<int> &nums, int idx)
    {
        bool left_flag{false}, right_flag{false};
        for (int left = idx - 1; left >= 0; --left)
        {
            if (nums[left] > nums[idx])
            {
                left_flag = true;
                break;
            }
            else if (nums[left] == nums[idx])
                continue;
            else
                break;
        }
        for (int right = idx + 1; right < nums.size(); ++right)
        {
            if (nums[right] > nums[idx])
            {
                right_flag = true;
                break;
            }
            else if (nums[right] == nums[idx])
                continue;
            else
                break;
        }
        return (left_flag && right_flag);
    }
};

int main(void)
{

    return 0;
}
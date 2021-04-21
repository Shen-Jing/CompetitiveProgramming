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
    bool canJump(vector<int>& nums)
    {
        return can_jump_recursive(nums, 0);
    }
  
  private:
    bool can_jump_recursive(const vector<int> &nums, int cur_idx)
    {
        int sz = nums.size();
        if (cur_idx == sz - 1)
            return true;

        int furthest_jump = min(cur_idx + nums[cur_idx], sz - 1);
        for (int jump = furthest_jump; jump >= 1; --jump)
            if (can_jump_recursive(nums, cur_idx + jump))
                return true;
        return false;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{3,2,1,0,4};
    cout << sol.canJump(nums) << "\n";

    nums = {3,2,2,0,4};
    cout << sol.canJump(nums) << "\n";

    nums = {2, 0};
    cout << sol.canJump(nums) << "\n";

    return 0;
}
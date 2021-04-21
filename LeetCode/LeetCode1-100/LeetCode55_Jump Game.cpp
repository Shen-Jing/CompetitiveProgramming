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
        bool ans_existence{false};
        can_jump_recursive(nums, 0, ans_existence);
        return ans_existence;
    }
  
  private:
    void can_jump_recursive(const vector<int> &nums, int cur_idx, bool &ans_existence)
    {
        if (cur_idx == nums.size() - 1)
        {
            ans_existence = true;
            return;
        }
        for (int jump = 1; jump <= nums[cur_idx] && cur_idx + jump < nums.size(); ++jump)
            can_jump_recursive(nums, cur_idx + jump, ans_existence);
        return;
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
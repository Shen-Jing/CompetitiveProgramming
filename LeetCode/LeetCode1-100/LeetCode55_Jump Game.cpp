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

enum class IndexType
{
    k_Good = 0,
    k_Bad,
    k_Unknown
};

class Solution
{
 public:
    bool canJump(vector<int>& nums)
    {
        can_jump.assign(nums.size(), IndexType::k_Unknown);
        can_jump.back() = IndexType::k_Good;
        return can_jump_greedy(nums);
        return can_jump_bottom_up_DP(nums);
        return can_jump_recursive(nums, 0);
    }
  
  private:
    vector<IndexType> can_jump;

    bool can_jump_recursive(const vector<int> &nums, int cur_idx)
    {
        int sz = nums.size();
        if (can_jump[cur_idx] != IndexType::k_Unknown)
            return (can_jump[cur_idx] == IndexType::k_Good) ? true : false;

        int furthest_idx = min(cur_idx + nums[cur_idx], sz - 1);
        for (int next_idx = furthest_idx; next_idx >= cur_idx + 1; --next_idx)
            if (can_jump_recursive(nums, next_idx))
            {
                can_jump[cur_idx] = IndexType::k_Good;
                return true;
            }
        can_jump[cur_idx] = IndexType::k_Bad;
        return false;
    }

    bool can_jump_bottom_up_DP(const vector<int> &nums)
    {
        int sz = nums.size();
        for (int i = sz - 2; i >= 0; --i)
        {
            int furthest_idx = min(i + nums[i], sz - 1);
            for (int next_idx = furthest_idx; next_idx >= i + 1; --next_idx)
                if (can_jump[next_idx] == IndexType::k_Good)
                {
                    can_jump[i] = IndexType::k_Good;
                    break;
                }
        }
        return can_jump[0] == IndexType::k_Good;
    }

    bool can_jump_greedy(const vector<int> &nums)
    {
        int sz = nums.size();
        int smallest_good_index = sz - 1;
        for (int i = sz - 2; i >= 0; --i)
        {
            if (i + nums[i] >= smallest_good_index)
                smallest_good_index = i;
        }
        return smallest_good_index == 0;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{3,2,1,0,4};  // False 
    cout << sol.canJump(nums) << "\n";

    nums = {3,2,2,0,4};  // True 
    cout << sol.canJump(nums) << "\n";

    nums = {2, 0};  // True 
    cout << sol.canJump(nums) << "\n";

    return 0;
}
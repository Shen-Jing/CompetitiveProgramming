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
    int jump(vector<int>& nums)
    {
        min_jumps.assign(nums.size(), max_jumps);
        min_jumps.back() = 0;
        return get_min_jump_recursive(nums, 0);
    }
  
  private:
    /* Constraints: 1 <= nums.length <= 10^4 */
    const int max_jumps = 10001;
    vector<int> min_jumps;

    int get_min_jump_recursive(const vector<int> &nums, int cur_idx)
    {
        if (min_jumps[cur_idx] != max_jumps)
            return min_jumps[cur_idx];
        int sz = nums.size();
        int furthest_pos = min(cur_idx + nums[cur_idx], sz - 1);
        for (int next_pos = furthest_pos; next_pos > cur_idx; --next_pos)
        {
            min_jumps[cur_idx] = min(min_jumps[cur_idx], 1 + get_min_jump_recursive(nums, next_pos));
        }
        return min_jumps[cur_idx];
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{2,3,0,1,4};  // 2 
    cout << sol.jump(nums) << "\n";

    return 0;
}
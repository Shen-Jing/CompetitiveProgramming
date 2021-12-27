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
    int maxProduct(vector<int> &nums)
    {
        return bottom_up_DP(nums);
    }

 private:
    int bottom_up_DP(vector<int> &nums)
    {
        int min_so_far{1}, max_so_far{1}, max_product{nums[0]};
        auto sz = nums.size();
        for (int i = 0; i < sz; ++i)
        {
            int curr{nums[i]};
            if (!curr)
                min_so_far = max_so_far = 0;  // Re:Zero!
            else
            {
                int old_min_so_far = min_so_far,
                    old_max_so_far = max_so_far;
                min_so_far = min(curr, 
                                 min(old_max_so_far * curr, old_min_so_far * curr));
                max_so_far = max(curr,
                                 max(old_max_so_far * curr, old_min_so_far * curr));
            }
            max_product = max(max_product, max_so_far);
        }
        return max_product;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{2,3,-2,4,-1};
    sol.maxProduct(nums);

    return 0;
}
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
    int lengthOfLIS(vector<int> &nums)
    {
        return DP(nums);
    }

 private:
    int DP(const vector<int> &nums)
    {
        int sz = nums.size();
        if (!sz)
            return 0;

        int ans = 1;
        vector<int> max_lens(sz, 0);
        for (int i = 0; i < sz; ++i)
        {
            max_lens[i] = 1;
            for (int prev_i = 0; prev_i < i; ++prev_i)
            {
                if (nums[i] > nums[prev_i])
                {
                    max_lens[i] = max(max_lens[prev_i] + 1, max_lens[i]);
                    ans = max(ans, max_lens[i]);
                }
            }
        }
        return ans;
    }
};

int main(void)
{
    return 0;
}
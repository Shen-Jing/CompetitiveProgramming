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
    int longestConsecutive(vector<int>& nums)
    {
        auto sz = nums.size();
        if (!sz)
            return 0;
        sort(nums.begin(), nums.end());
        int max_len{1}, cur_len;
        for (size_t i = 0; i < sz - 1; ++i)
        {
            cur_len = 1;
            while (i < sz - 1 && nums[i + 1] - nums[i] <= 1)
            {
                if (nums[i] + 1 == nums[i + 1])
                    ++cur_len;
                ++i;
            }
            max_len = max(max_len, cur_len);
        }
        return max_len;
    }
};

int main(void)
{

    return 0;
}
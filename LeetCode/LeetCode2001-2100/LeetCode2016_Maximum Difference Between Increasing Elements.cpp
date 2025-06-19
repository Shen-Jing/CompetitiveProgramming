#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
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
    int maximumDifference(vector<int>& nums)
    {
        int prefix_min = nums[0], max_diff = -1;
        size_t sz = nums.size();
        for (size_t i = 1; i < sz; ++i)
        {
            if (prefix_min < nums[i])
            {
                max_diff = max(max_diff, nums[i] - prefix_min);
            }
            prefix_min = min(prefix_min, nums[i]);
        }
        return max_diff;
    }
};

int main(void)
{

    return 0;
}
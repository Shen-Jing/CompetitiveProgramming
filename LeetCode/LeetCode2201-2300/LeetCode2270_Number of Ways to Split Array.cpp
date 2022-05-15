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
    int waysToSplitArray(vector<int>& nums)
    {
        int sz = nums.size();
        vector<long long> prefix_sums(sz, 0);
        prefix_sums[0] = nums[0];
        for (int i = 1; i < sz; ++i)
        {
            prefix_sums[i] = prefix_sums[i - 1] + nums[i];
        }
        
        int ans{0};
        for (int i = 0; i < sz - 1; ++i)
        {
            long long left_part = prefix_sums[i],
                right_part = prefix_sums.back() - prefix_sums[i];
            if (left_part >= right_part)
                ++ans;
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}
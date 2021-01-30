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
#include <numeric>
#include <queue>
#include <tuple>
#include <type_traits>
#include <utility>
#include <regex>
#include <set>
#include <stack>
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
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> ans;
        auto sz = nums.size();
        for (size_t i = 0; i < sz; ++i)
            for (size_t j = i + 1; j < sz; ++j)
                if (nums[i] + nums[j] == target)
                {
                    ans.emplace_back(i);
                    ans.emplace_back(j);
                }
        return ans;
    }
};

int main(void)
{

    return 0;
}
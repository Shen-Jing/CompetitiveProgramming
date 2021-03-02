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
    int firstMissingPositive(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        auto result_it = find_if(nums.begin(), nums.end(), [](int i){ return i > 0; });
        bool found{false};
        for ( ; result_it != nums.end() - 1; ++result_it)
            if (*(result_it + 1) - *result_it != 1)
            {
                found = true;
                break;
            }
        if (found)
            return *result_it + 1;
        return *(result_it + 1) + 1;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums{3, 1, 2, 0, -1};
    sol.firstMissingPositive(nums);

    return 0;
}
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
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        unordered_map<int, int> occurencies;
        for (int num : nums)
        {
            if (!occurencies.count(num))
                occurencies[num] = 0;
            ++occurencies[num];
        }
        
        for (const auto &num : nums)
        {
            if (occurencies[num])
            {
                int cur_streak{1};
                for (auto cur_num = num + 1; occurencies.count(cur_num) >= 1; ++cur_num)
                {
                    ++cur_streak;
                    if (cur_streak == k)
                        break;
                }

                if (cur_streak == k)
                {
                    /* Decrease frequency of current set of k consecutive numbers */
                    for (int value{num}; value < num + k; ++value)
                    {
                        --occurencies[value];
                    }
                }
                else
                    return false;
            }
        }
        return true;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums{3,3,2,2,1,1};
    sol.isPossibleDivide(nums, 4);
    return 0;
}
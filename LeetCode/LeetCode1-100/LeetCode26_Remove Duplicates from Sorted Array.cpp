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
    int removeDuplicates(vector<int> &nums)
    {
    }

    /* First method: out-of-place  */
    int intuition(vector<int> &nums)
    {
        unordered_map<int, int> counter;
        for (const auto &num : nums)
            ++counter[num];
        int num_of_unique = counter.size();
        auto iter = nums.begin();
        for (const auto &[num, cnt] : counter)
        {
            *iter = num;
            ++iter;
        }
        sort(nums.begin(), nums.begin() + num_of_unique);
        return num_of_unique;
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};

    sol.removeDuplicates(nums);

    return 0;
}
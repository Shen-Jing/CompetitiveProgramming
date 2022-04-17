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
    int findClosestNumber(vector<int>& nums)
    {
        vector<int> ans;
        int min_diff = numeric_limits<int>::max();
        for (const auto &num : nums)
        {
            if (abs(num - 0) < min_diff)
            {
                min_diff = abs(num - 0);
            }
        }
        for (const auto &num : nums)
        {
            if (abs(num - 0) == min_diff)
            {
                ans.emplace_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans.back();
    }
};

int main(void)
{

    return 0;
}
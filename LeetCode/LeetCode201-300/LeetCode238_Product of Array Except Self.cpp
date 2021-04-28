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
    vector<int> productExceptSelf(vector<int>& nums)
    {
        size_t sz{nums.size()};
        vector<int> ans(sz, 1);
        /* left product */
        for (int i = 1; i < sz; ++i)
            ans[i] = ans[i - 1] * nums[i - 1];
        /* right product */
        int right = 1;
        for (int i = sz - 1; i >= 0; --i)
        {
            ans[i] *= right;
            right *= nums[i];
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}
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
    void moveZeroes(vector<int>& nums)
    {
        vector<int> ans;
        int cnt = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!nums[i])
                ++cnt;
            else
                ans.emplace_back(nums[i]);
        }
        for (int i = 0; i < cnt; ++i)
            ans.emplace_back(0);
        nums = move(ans);
        return;
    }
};

int main(void)
{

    return 0;
}
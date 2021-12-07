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
    void sortColors(vector<int> &nums)
    {

    }

    void my_counting_sort(vector<int> &nums)
    {
        int max_val{2}, min_val{0}, val_range;
        val_range = max_val - min_val + 1;
        vector<int> cnt(val_range, 0);
        for (const auto &num : nums)
            ++cnt[num - min_val];
        for (int i = 1; i < val_range; ++i)
            cnt[i] += cnt[i - 1];

        auto sz = nums.size();
        vector<int> ans(sz, 0);
        for (int i = sz - 1; i >= 0; --i)
        {
            auto &pos = cnt[nums[i] - min_val];
            ans[pos - 1] = nums[i];
            --pos;
        }
        swap(ans, nums);
        return;
    }
};

int main(void)
{

    return 0;
}
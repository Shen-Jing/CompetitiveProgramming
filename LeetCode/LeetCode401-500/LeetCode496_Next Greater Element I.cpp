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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        for (const auto &target : nums1)
        {
            auto target_pos = lower_bound(nums2.begin(), nums2.end(), target);
            advance(target_pos, 1);
            auto next_greater_pos = lower_bound(target_pos, nums2.end(), target);
            if (next_greater_pos != nums2.end())
                ans.emplace_back(*next_greater_pos);
            else
                ans.emplace_back(-1);
        }
        return ans;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums1{4,1,2}, nums2{1,3,4,2};
    sol.nextGreaterElement(nums1, nums2);

    return 0;
}
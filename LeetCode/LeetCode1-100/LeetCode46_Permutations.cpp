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

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int sz{nums.size()};
        my_permute(ans, nums, 0, sz);
        return ans;
    }
    void my_permute(vector<vector<int>> &ans, vector<int> &nums, int idx, int &sz)
    {
        if (idx == sz - 1)
        {
            ans.emplace_back(nums);
            return;
        }
        for (int i = idx; i < sz; ++i)
        {
            swap(nums[idx], nums[i]);
            my_permute(ans, nums, idx + 1, sz);
            swap(nums[idx], nums[i]);
        }
        return;
    }
};
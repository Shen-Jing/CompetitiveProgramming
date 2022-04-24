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
    vector<int> intersection(vector<vector<int>>& nums)
    {
    }

 private:
    vector<int> by_map(vector<vector<int>> &nums)
    {
        unordered_map<int, int> nums_freq;
        for (const auto &num : nums)
            for (const auto &n : num)
                ++nums_freq[n];

        int sz = nums.size();
        vector<int> ans;
        for (const auto &[num, freq] : nums_freq)
            if (freq == sz)
                ans.emplace_back(num);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(void)
{

    return 0;
}
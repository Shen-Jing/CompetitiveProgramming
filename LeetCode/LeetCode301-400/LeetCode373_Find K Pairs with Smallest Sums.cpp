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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
    }

 private:
    vector<vector<int>> brute_force(vector<int>& nums1, vector<int>& nums2, int k)
    {
        map<int, vector<int>> sum2pair;
        vector<vector<int>> ans;
        for (const auto &num1 : nums1)
            for (const auto &num2 : nums2)
            {
                ans.push_back({num1, num2});
            }
        if (k > ans.size())
            k = ans.size();
        partial_sort(ans.begin(), ans.begin() + k, ans.end(), [](const auto &lhs, const auto &rhs)
        {
            return (lhs[0] + lhs[1]) < (rhs[0] + rhs[1]);
        });
        return vector<vector<int>>(ans.begin(), ans.begin() + k);
    }
};

int main(void)
{

    return 0;
}
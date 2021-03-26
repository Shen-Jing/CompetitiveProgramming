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
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        return BST_way(nums, k);
    }

  private:
    vector<int> BST_way(vector<int> &nums, int k)
    {
        multiset<int> BST;
        for (int i = 0; i < k; ++i)
            BST.emplace(nums[i]);

        vector<int> ans{*BST.rbegin()};
        int sz = nums.size();  
        /* Cannot be size_t (because sz - 2 will underflow when sz is 1) */
        for (int left = 0, right = k - 1; right <= sz - 2; )
        {
            BST.erase(BST.find(nums[left++]));
            BST.emplace(nums[++right]);
            ans.emplace_back(*BST.rbegin());
        }
        return ans;
    }
};

int main(void)
{
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k{3};
    Solution sol;
    sol.maxSlidingWindow(nums, k);
    return 0;
}
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
    }

 private:
    /* Not in-place */
    void not_inplace(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> ans;
        ans.reserve(m + n);
        int idx1{0}, idx2{0};
        for (; idx1 < m && idx2 < n; )
        {
            if (nums1[idx1] <= nums2[idx2])
            {
                ans.emplace_back(nums1[idx1]);
                ++idx1;
            }
            else
            {
                ans.emplace_back(nums2[idx2]);
                ++idx2;
            }
        }
        for (; idx1 < m; ++idx1)
            ans.emplace_back(nums1[idx1]);
        for (; idx2 < n; ++idx2)
            ans.emplace_back(nums2[idx2]);
        swap(nums1, ans);
    }
};

int main(void)
{

    return 0;
}
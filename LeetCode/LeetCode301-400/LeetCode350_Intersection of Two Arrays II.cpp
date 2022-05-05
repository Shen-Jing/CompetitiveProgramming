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
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        return by_sorting(nums1, nums2);
    }

 private:
    vector<int> by_hashmap(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> freqs;
        for (const auto &num : nums2)
        {
            ++freqs[num];
        }

        vector<int> ans;
        for (const auto &num : nums1)
        {
            if (freqs[num] > 0)
            {
                ans.emplace_back(num);
                --freqs[num];
            }
        }
        return ans;
    }

    vector<int> by_sorting(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;
        int sz1 = nums1.size(), sz2 = nums2.size();
        for (int i1 = 0, i2 = 0; i1 < sz1 && i2 < sz2; )
        {
            int num1 = nums1[i1], num2 = nums2[i2];
            if (num1 == num2)
            {
                ans.emplace_back(num1);
                ++i1, ++i2;
            }
            else if (num1 > num2)
            {
                ++i2;
            }
            else
            {
                ++i1;
            }
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}
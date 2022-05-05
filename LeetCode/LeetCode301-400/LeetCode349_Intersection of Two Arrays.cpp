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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
    }

 private:
    vector<int> two_sets(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> nums_set1, nums_set2;
        for (const auto &num : nums1)
            nums_set1.emplace(num);
        for (const auto &num : nums2)
            nums_set2.emplace(num);
        
        vector<int> ans;
        for (const auto &num1 : nums_set1)
        {
            if (nums_set2.count(num1))
            {
                ans.emplace_back(num1);
            }
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}
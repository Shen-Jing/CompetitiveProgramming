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
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k)
    {
        vector<int> keys_idx;
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] == key)
                keys_idx.emplace_back(i);

        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (const auto &key_idx : keys_idx)
            {
                if (abs(i - key_idx) <= k)
                {
                    ans.emplace_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}
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
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        return two_sum_onepass(numbers, target);
    }

 private:
    vector<int> ans_{1, 2};

    vector<int> two_sum_onepass(vector<int>& nums, int target)
    {
        unordered_map<int, int> num_to_index;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto cur_num = nums[i];
            if (num_to_index.count(target - cur_num))
            {
                ans_[0] = num_to_index[target - cur_num] + 1;
                ans_[1] = i + 1;
                break;
            }
            num_to_index[cur_num] = i;
        }
        return ans_;
    }
};

int main(void)
{

    return 0;
}
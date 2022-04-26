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
    int findDuplicate(vector<int> &nums)
    {
        return by_sort(nums);
    }
  
 private:
    int by_sort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] == nums[i - 1])
                return nums[i];
        return nums[0];
    }
    /*: 
      Original: [1, n] (size: n)
      + duplicate => size n -> n + 1
      BUT, not exactly correct (because duplicate"s" are not only 1: [1,1,1,2,3])
    */
    int math_method(vector<int> &nums)
    {
        int sz = nums.size(),
            n{sz - 1};
        int no_dup_sum = (1 + n) * n / 2,
            contain_dup_sum = accumulate(nums.begin(), nums.end(), 0);
        return contain_dup_sum - no_dup_sum;
    }
};

int main(void)
{

    return 0;
}
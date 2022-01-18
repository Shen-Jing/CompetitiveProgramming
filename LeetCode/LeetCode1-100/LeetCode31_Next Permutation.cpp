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
    void nextPermutation(vector<int> &nums)
    {
        linear_solve(nums);
        return;
    }

 private:
    void STL_next_permutation(vector<int> &nums)
    {
        next_permutation(nums.begin(), nums.end());
        return;
    }

    void linear_solve(vector<int> &nums)
    {
        int idx = (nums.size() - 1) - 1;
        for ( ; idx >= 0; --idx)
            if (nums[idx] < nums[idx + 1])
                break;
        if (idx < 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }

        for (int j = nums.size() - 1; j >= 0; --j)
            if (nums[j] > nums[idx])
            {
                swap(nums[j], nums[idx]);
                break;
            }
        reverse(nums.begin() + idx + 1, nums.end());
    }
};

int main(void)
{

    return 0;
}
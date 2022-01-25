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
    Solution()
    {
        factorial_[0] = 1;
        for (int n = 1; n <= maxn_; ++n)
            factorial_[n] = n * factorial_[n - 1];
    }

    string getPermutation(int n, int k)
    {
        string result;
        vector<int> nums(n, 0);
        iota(nums.begin(),  nums.end(), 1);
        --k;
        for (int i = n; i >= 1; --i)
        {
            int quotient = k / factorial_[i - 1];
            result += to_string(nums[quotient]);
            nums.erase(nums.begin() + quotient);
            k %= factorial_[i - 1];
        }
        return result;
    }

 private:
    inline constexpr static int maxn_{9};
    array<int, maxn_ + 1> factorial_;
};

int main(void)
{

    return 0;
}
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
        memo_.fill(kN);
        /* Base cases */
        memo_[0] = 0;
        for (int i{1}, max_root = sqrt(kN); i <= max_root; ++i)
            memo_[i * i] = 1;
    }

    int numSquares(int n)
    {
        return top_down(n);
    }

 private:
    inline static const int kN{10001};
    array<int, kN> memo_;

    int top_down(const int &n)
    {
        if (memo_[n] != kN)
            return memo_[n];
        int sqrt_root_n = sqrt(n);
        for (int i = 1; i <= sqrt_root_n; ++i)
            memo_[n] = min(memo_[n], top_down(n - i * i) + 1);
        return memo_[n];
    }

    int bottom_up(const int &n)
    {
        return memo_[n];
    }
};

int main(void)
{
    Solution sol;

    cout << sol.numSquares(5156) << "\n";  // 2
    cout << sol.numSquares(6175) << "\n";  // 4

    return 0;
}
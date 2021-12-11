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
    int nthMagicalNumber(int n, int a, int b)
    {
        return my_brute_force(n, a, b);
    }

    int my_brute_force(const int &n, const int &a, const int &b)
    {
        constexpr int MOD{1000'000'007};
        set<uint64_t> magical_nums;
        for (int i = 1; i <= n; ++i)
        {
            uint64_t mult_of_a = a,
                     mult_of_b = b;
            mult_of_a *= i;
            mult_of_b *= i;
            magical_nums.emplace(mult_of_a);
            magical_nums.emplace(mult_of_b);
        }
        return *next(magical_nums.begin(), n - 1) % MOD;
    }
};

int main(void)
{

    return 0;
}
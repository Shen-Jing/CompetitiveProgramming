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
        return binary_search_answer(n, a, b);
        return my_brute_force(n, a, b);
    }

 private:
    const int MOD_{1000'000'007};
    int my_brute_force(const int &n, const int &a, const int &b)
    {
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
        return *next(magical_nums.begin(), n - 1) % MOD_;
    }

    /* Greatest Common Divisors */
    int gcd(int a, int b)
    {
        /* Assume a always be larger */
        while (b)
        {
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    int gcd_recursive(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd_recursive(b, a % b);
    }

    /* Longest Common Multiple */
    uint64_t lcm(uint64_t a, uint64_t b)
    {
        return a * b / gcd(a, b);
    }

    /* The number of magical numbers are less than or equal to"n". */
    int get_num_of_magicals(const uint64_t &n, const uint64_t &a, const uint64_t &b, const uint64_t &l)
    {
        return n / a + n / b - n / l;
    }

    int binary_search_answer(const uint64_t &n, const uint64_t &a, const uint64_t &b)
    {
        /* Assume a < b */
        if (a > b)
            return binary_search_answer(n, b, a);
        uint64_t left = a, right = a * n, lcm_ab = lcm(a, b);
        while (left < right)
        {
            uint64_t mid = left + ((right - left) >> 1);
            if (get_num_of_magicals(mid, a, b, lcm_ab) < n)
                left = mid + 1;
            else
                right = mid;
        }
        return left % MOD_;
    }
};

int main(void)
{
    Solution sol;
    int n, a, b;

    sol.nthMagicalNumber(n = 4, a = 2, b = 3);  // 6
    sol.nthMagicalNumber(n = 25, a = 4, b = 6);  // 6
    sol.nthMagicalNumber(1000000000, 40000, 40000);  // 999720007

    return 0;
}
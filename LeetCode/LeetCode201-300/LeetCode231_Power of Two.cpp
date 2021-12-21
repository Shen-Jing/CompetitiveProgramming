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
    bool isPowerOfTwo(int n)
    {
        check_table(n);
    }

    bool check_table(const int &n)
    {
        if (!Solution::powers_of_two.size())
        {
            Solution::powers_of_two.emplace(1);
            for (int pow_n = 1; pow_n <= 31; ++pow_n)
            {
                int64_t num = static_cast<int64_t>(pow(2, pow_n));
                Solution::powers_of_two.emplace(num);
                Solution::powers_of_two.emplace(-num);
            }
        }
        return Solution::powers_of_two.count(n) == 1;
    }

 private:
    static unordered_set<int64_t> powers_of_two;
};

unordered_set<int64_t> Solution::powers_of_two;

int main(void)
{
    Solution sol;

    cout << sol.isPowerOfTwo(32) << "\n";
    cout << sol.isPowerOfTwo(2147483647) << "\n";
    cout << sol.isPowerOfTwo(-2147483648) << "\n";
    cout << sol.isPowerOfTwo(0) << "\n";
    cout << sol.isPowerOfTwo(-16) << "\n";

    return 0;
}
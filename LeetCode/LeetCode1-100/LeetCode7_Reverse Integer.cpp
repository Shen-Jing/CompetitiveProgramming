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
    int reverse(int x)
    {
        return use_STL(x);
    }
  
  private:
    bool is_overflow(string s, size_t digits)
    {
        if (s.back() != '0' && s.length() >= digits)
            return true;
        return false;
    }

    /* Range: [-2147483648, 2147483647] */
    int use_STL(int x)
    {
        string str_x{to_string(x)};

        size_t max_digits = (x >= 0) ? 10 : 11;
        if (is_overflow(str_x, max_digits))
            return 0;

        if (x < 0)
            std::reverse(str_x.begin() + 1, str_x.end());
        else
            std::reverse(str_x.begin(), str_x.end());
        return stoi(str_x);
    }
};

int main(void)
{
    Solution sol;

    cout << sol.reverse(123) << "\n";
    cout << sol.reverse(-120) << "\n";
    cout << sol.reverse(-2147483648) << "\n";
    return 0;
}
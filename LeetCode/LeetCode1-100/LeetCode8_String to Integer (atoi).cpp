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
    int myAtoi(string s)
    {
        return reinvent(s);
    }

 private:
    int reinvent(string str)
    {
        int sign{1};
        int result{0};
        size_t i{0};

        while (str[i] == ' ')
            ++i;
        if (str[i] == '-' || str[i] == '+')
            sign = (str[i++] == '+') ? 1 : -1;

        for ( ; i < str.length() && isdigit(str[i]); ++i)
        {
            if (result > INT32_MAX / 10 || (result == INT32_MAX / 10 && str[i] - '0' > INT32_MAX % 10))
                return (sign == 1) ? INT32_MAX : INT32_MIN;
            result = result * 10 + (str[i] - '0');
        }
        return sign * result;
    }
};

int main(void)
{

    return 0;
}
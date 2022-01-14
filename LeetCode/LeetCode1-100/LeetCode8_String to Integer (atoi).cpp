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
        bool is_positive{true}, done{false};
        int result{0};
        for (size_t i{0}; i < str.length(); ++i)
        {
            if (str[i] == '-' || str[i] == '+')
            {
                is_positive = (str[i] == '+') ? true : false;
                if (i == str.length() - 1 || !isdigit(str[i + 1]))
                    return 0;
            }
            if (isdigit(str[i]) && !done)
            {
                for ( ; isdigit(str[i]) ; ++i)
                    result = result * 10 + (str[i] - '0');
                done = true;
            }
            if (done)
                break;
        }
        result = is_positive ? result : -result;
        return result;
    }
};

int main(void)
{

    return 0;
}
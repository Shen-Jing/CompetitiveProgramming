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
    bool isValid(string s) 
    {
        /* round, curly, square */
        stack<char> open_brackets;
        map<char, char> bracket_mapping{ {'(', ')'}, {'[', ']'}, {'{', '}'} };
        for (const auto &bracket : s)
        {
            if (bracket_mapping.count(bracket))  // C++20: .contains
                open_brackets.push(bracket);
            else
            {
                if (open_brackets.empty() || bracket_mapping[open_brackets.top()] != bracket)
                    return false;
                open_brackets.pop();
            }
        }

        if (!open_brackets.empty())
            return false;
        return true;
    }
};

int main(void)
{
    Solution sol;
    sol.isValid("())");
    return 0;
}
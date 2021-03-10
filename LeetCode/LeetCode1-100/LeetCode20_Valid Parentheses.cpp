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
        array<stack<char>, 3> brackets_stack;
        map<char, int> open_brackets {{'(', 0}, {'[', 1}, {'{', 2}};
        map<char, int> close_brackets{{')', 0}, {']', 1}, {'}', 2}};
        for (const auto &bracket : s)
        {
            if (open_brackets.count(bracket))
                brackets_stack[open_brackets[bracket]].emplace(bracket);
            else
                brackets_stack[close_brackets[bracket]].pop();
        }

        for (const auto &bracket : brackets_stack)
            if (!bracket.empty())
                return false;
        return true;
    }
};

int main(void)
{

    return 0;
}
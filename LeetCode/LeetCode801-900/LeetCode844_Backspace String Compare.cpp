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
    bool backspaceCompare(string s, string t)
    {
    }

 private:
    bool backspace_comp_by_stack(const string &s, const string &t)
    {
        string typed_s = typed_by_stack(s),
               typed_t = typed_by_stack(t);
        return typed_s == typed_t;
    }

    string typed_by_stack(const string &str)
    {
        vector<char> stk;
        for (const auto &ch : str)
        {
            if (ch != '#')
            {
                stk.emplace_back(ch);
            }
            else if (!stk.empty())
            {
                stk.pop_back();
            }
        }
        return string(stk.begin(), stk.end());
    }
};

int main(void)
{

    return 0;
}
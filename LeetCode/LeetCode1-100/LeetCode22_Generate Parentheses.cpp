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
    vector<string> generateParenthesis(int n)
    {
        ans.reserve(100);
        generate_traceback("", 0, 2 * n);
        return ans;
    }
  
  private:
    vector<string> ans;

    bool is_valid_parenthesis(const string &input)
    {
        stack<char> open_brackets;
        for (const auto &ch : input)
        {
            if (ch == '(')
                open_brackets.emplace(ch);
            else
            {
                if (open_brackets.empty())
                    return false;
                open_brackets.pop();
            }
        }
        if (!open_brackets.empty())
          return false;
        return true;
    }

    void generate_traceback(string cur_output, const int &cur, const int &n)
    {
        if (cur == n)
        {
            if (is_valid_parenthesis(cur_output))
                ans.emplace_back(cur_output);
            return;
        }
        cur_output += "(";
        generate_traceback(cur_output, cur + 1, n);
        cur_output.back() = ')';
        generate_traceback(cur_output, cur + 1, n);
    }
};

int main(void)
{

    return 0;
}
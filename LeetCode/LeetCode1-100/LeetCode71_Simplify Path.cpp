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
    string simplifyPath(string path)
    {
        vector<string> stk;
        string_view strv_path(path);
        int len = strv_path.length();
        int i{1}, slash_pos;
        while (i < len)
        {
            slash_pos = strv_path.find('/', i);
            if (slash_pos == string_view::npos)
                break;
          
            string_view path_token = strv_path.substr(i, slash_pos - i);
            i = slash_pos + 1;
            if (path_token.empty())
                continue;
            if (path_token == ".."sv)
            {
                if (!stk.empty())
                    stk.pop_back();
            }
            else if (path_token != "."sv)
                stk.emplace_back(path_token);
        }

        string canonical_path;
        for (const auto &s : stk)
            canonical_path += "/" + s;
        return (canonical_path.empty()) ? "/" : canonical_path;
    }
};

int main(void)
{
    Solution sol;

    /* 200 / 256 test cases passed. */
    sol.simplifyPath("/a//b////c/d//././/..");
    sol.simplifyPath("/../");
    sol.simplifyPath("/home//foo/");

    return 0;
}
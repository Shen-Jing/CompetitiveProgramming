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
    int lengthOfLongestSubstring(string s)
    {
        int max_length = 0;
        auto sz = s.size();
        for (size_t i = 0; i < sz; ++i)
        {
            for (size_t j = sz - 1; j >= i; --j)
            {
                int cur_length = j - i + 1;
                if (cur_length < max_length)
                    break;
                auto tmp_substr = s.substr(i, cur_length);
                if (check_unique(tmp_substr) && cur_length > max_length)
                    max_length = cur_length;
            }
        }
        return max_length;
    }

    bool check_unique(string &str)
    {
        set<int> substr_set;
        for (size_t i = 0; i < str.length(); ++i)
            if (substr_set.count(str[i]))
            // if (substr_set.contains(str[i]))  // C++20
                return false;
            else
                substr_set.emplace(str[i]);
        return true;
    }
};

int main(void)
{
    Solution sol;
    string str{"abcabcbb"};
    cout << sol.lengthOfLongestSubstring(str) << "\n";
    return 0;
}
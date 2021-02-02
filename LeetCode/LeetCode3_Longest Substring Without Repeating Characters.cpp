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
        for (size_t sub_start = 0; sub_start < sz; ++sub_start)
        {
            for (size_t sub_end = sz; sub_end > sub_start; --sub_end)
            {
                int cur_length = sub_end - sub_start;
                if (cur_length < max_length)
                    break;
                if (check_unique(s, sub_start, sub_end))
                    max_length = max(max_length, cur_length);
            }
        }
        return max_length;
    }

    bool check_unique(string &str, size_t start, size_t end)
    {
        set<int> substr_set;
        for (size_t i = start; i < end; ++i)
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
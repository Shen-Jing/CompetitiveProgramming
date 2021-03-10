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
        unordered_map<char, size_t> position;
        size_t max_length = 0;
        auto sz = s.size();
        for (size_t sub_start = 0, idx = 0; idx < sz; ++idx)
        {
            if (position.count(s[idx]))
                sub_start = max(sub_start, position[s[idx]] + 1);
            max_length = max(max_length, idx - sub_start + 1);
            position[s[idx]] = idx;
        }
        return max_length;
    }
};

int main(void)
{
    Solution sol;
    // string str{"abcabcbb"};
    string str{"tmmzuxt"};
    cout << sol.lengthOfLongestSubstring(str) << "\n";
    return 0;
}
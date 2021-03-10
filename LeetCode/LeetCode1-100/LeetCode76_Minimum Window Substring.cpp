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
    string minWindow(string s, string t)
    {
        set<char> lack_chars, target_chars;
        for (const auto &ch : t)
        {
            lack_chars.emplace(ch);
            target_chars.emplace(ch);
        }
        size_t left = 0, right = 0;
        auto sz = s.size();
        for ( ; left < sz && right < sz; )
        {
            if (lack_chars.count(s[right]) && lack_chars.size() == 1)
            {
                lack_chars.erase(s[right]);
                lack_chars.emplace(s[left]);
                ++left;
            }
            else
            {
                ++right;
            }
        }
        return s.substr(left, right - left + 1);
    }
};

int main(void)
{

    return 0;
}
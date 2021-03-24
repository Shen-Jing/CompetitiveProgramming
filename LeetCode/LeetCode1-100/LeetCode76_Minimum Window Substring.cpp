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

enum Ans
{
    k_min_len = 0,
    k_left,
    k_right,
};

class Solution
{
 public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> cur_freq, target_freq;
        for (const auto &ch : t)
            ++target_freq[ch];

        auto required = target_freq.size();
        decltype(required) formed = 0;
        auto sz = s.size();
        
        array<int, 3> ans{static_cast<int>(sz) + 1, 0, -1};
        for (size_t left = 0, right = 0; left < sz && right < sz; ++right)
        {
            auto cur_char = s[right];
            ++cur_freq[cur_char];
            if (target_freq.count(cur_char) && cur_freq[cur_char] == target_freq[cur_char])
            {
                ++formed;
                while (formed == required && left < sz)
                {
                    if (ans[Ans::k_min_len] > right - left + 1)
                    {
                        // cout << ans[Ans::k_min_len] << " " <<  ans[Ans::k_left]  << ", "<< ans[Ans::k_right] << "\n";
                        ans[Ans::k_min_len] = right - left + 1;
                        ans[Ans::k_left] = left;
                        ans[Ans::k_right] = right;
                    }
                    auto removed = s[left];
                    --cur_freq[removed];
                    ++left;

                    if (target_freq.count(removed) && cur_freq[removed] < target_freq[removed])
                    {
                        --formed;
                        break;
                    }
                }
            }
        }
        if (ans[Ans::k_right] == -1)
            return "";
        /* Cannot use `ans` as length of answer (with **no check**).
           Otherwise it will get WA when no answer (i.g., s = "a", t = "b") */
        return s.substr(ans[Ans::k_left], ans[Ans::k_min_len]);
    }
};

int main(void)
{
    Solution sol;
    cout << sol.minWindow(string("ADOBECODEBANC"), string("ABC")) << "\n";
    cout << sol.minWindow(string("cabwefgewcwaefgcf"), string("cae")) << "\n";
    cout << sol.minWindow(string("a"), string("a")) << "\n";
    cout << sol.minWindow(string("a"), string("b")) << "\n";
    return 0;
}
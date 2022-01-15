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
    int countSubstrings(string s)
    {
        return count_by_extend(s);
        return count_top_down(s);
        return count_substrings_by_DP(s);
    }
 
 private:
    /* [start][end]: palindromic lenght of substr(start, end - start + 1) */
    vector<vector<int>> palindrome_len;
    vector<vector<int>> memo;

    int count_top_down(const string &s)
    {
        int cnt{0};
        memo.assign(s.length(), vector<int>(s.length(), -1));
        for (int start = 0; start < s.length(); ++start)
            for (int end = start; end < s.length(); ++end)
                cnt += is_palindrome(s, start, end);
        return cnt;
    }

    int is_palindrome(const string &input, int start, int end)
    {
        auto &memo_ref = memo[start][end];
        if (memo_ref != -1)
            return memo_ref;
        if (start >= end)
            return 1;
        return memo_ref = (input[start] == input[end]) ? is_palindrome(input, start + 1, end - 1) : 0;
    }

    int count_substrings_by_DP(const string &input)
    {
        const int len = input.length();
        palindrome_len.assign(len, vector<int>(len, 0));
        /* [Start, End] */
        for (int s = len - 1; s >= 0; --s)
            for (int e = s; e < len; ++e)
            {
                if (s == e)
                    palindrome_len[s][e] = 1;
                else
                    palindrome_len[s][e] = (input[s] == input[e] && (e - s == 1 || palindrome_len[s + 1][e - 1] > 0))
                                         ? palindrome_len[s + 1][e - 1] + 2
                                         : 0;
            }
        
        int cnt = 0;
        for (auto &outer : palindrome_len)
            for (auto &inner : outer)
                cnt += (inner != 0);
        return cnt;
    }

    int count_by_extend(const string &str)
    {
        int cnt{0};
        for (int center_idx{0}; center_idx < str.length(); ++center_idx)
        {
            /* Odd length */
            ++cnt;
            for (int left_idx = center_idx - 1,
                     right_idx = center_idx + 1;
                 left_idx >= 0 && right_idx < str.length();
                 --left_idx, ++right_idx)
            {
                if (str[left_idx] == str[right_idx])
                    ++cnt;
                else
                    break;
            }
            /* Even length */
            if (center_idx + 1 < str.length() && str[center_idx] == str[center_idx + 1])
            {
                ++cnt;
                for (int left_idx = center_idx - 1,
                        right_idx = center_idx + 2;
                    left_idx >= 0 && right_idx < str.length();
                    --left_idx, ++right_idx)
                {
                    if (str[left_idx] == str[right_idx])
                        ++cnt;
                    else
                        break;
                }
            }
        }
        return cnt;
    }
};

int main(void)
{
    Solution sol;
    
    sol.countSubstrings("aaa");
    sol.countSubstrings("fdsklf");

    return 0;
}
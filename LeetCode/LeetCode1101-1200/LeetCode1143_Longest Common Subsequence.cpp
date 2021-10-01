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
    int longestCommonSubsequence(string text1, string text2)
    {
        return LCS_bottom_up(text1, text2);
    }

 private:
    int LCS_bottom_up(const string &t1, const string &t2)
    {
        auto len1 = t1.length(), len2 = t2.length();
        vector<vector<int>> memo(len1, vector<int>(len2, 0));

        /* Init */
        bool has_common{false};
        for (size_t r = 0; r < len1; ++r)
            if (t1[r] == t2[0] || has_common)
            {
                memo[r][0] = 1;
                has_common = true;
            }
        for (size_t c = 0; c < len2; ++c)
            if (t1[0] == t2[c] || has_common)
            {
                memo[0][c] = 1;
                has_common = true;
            }

        for (size_t r = 1; r < len1; ++r)
            for (size_t c = 1; c < len2; ++c)
            {
                if (t1[r] == t2[c])
                    memo[r][c] = memo[r - 1][c - 1] + 1;
                else
                    memo[r][c] = max(memo[r - 1][c], memo[r][c - 1]);
            }
        return memo[len1 - 1][len2 - 1];
    }
};

int main(void)
{
    Solution sol;

    string t1{"abcde"}, t2{"ace"};
    sol.longestCommonSubsequence(t1, t2);

    t1 = string("bsbininm"), t2 = string("jmjkbkjkv");
    sol.longestCommonSubsequence(t1, t2);

    t1 = string("oxcpqrsvwf"), t2 = string("shmtulqrypy");
    sol.longestCommonSubsequence(t1, t2);

    return 0;
}
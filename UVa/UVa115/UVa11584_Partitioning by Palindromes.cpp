#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <map>
#include <regex>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

using namespace std;

void dp_palindrome(const string &str, vector<vector<bool>> &is_palin)
{
    // check all subsequence is palindrome or not
    auto len = str.length();
    for (int c = 0; c < len; ++c)
    {
        for (int r = 0; r <= c; ++r)
        {
            if (r == c)
            {
                is_palin[r][c] = true;
                continue;
            }
            if (str[r] == str[c])
                is_palin[r][c] = (c - r == 1) || is_palin[r + 1][c - 1];
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int kase;
    cin >> kase;
    for (int k = 1; k <= kase; ++k)
    {
        string input;
        cin >> input;
        // 2d dp array
        auto len = input.length();
        vector<vector<bool>> is_palin(len, vector<bool>(input.length(), false));
        dp_palindrome(input, is_palin);
        
        auto dp = vector<int>(len, 1);
        for (int i = 1; i < len; ++i)
        {
            dp[i] = dp[i - 1] + 1;  // possible value; Is it possible maximum? (Not exactly.)
            // subsequence start index
            if (is_palin[0][i])
                dp[i] = 1;
            else
            {
                for (int sub_idx = 1; sub_idx <= i; ++sub_idx)
                {
                    if (is_palin[sub_idx][i] && dp[sub_idx - 1] + 1 < dp[i])
                        dp[i] = dp[sub_idx - 1] + 1;
                }
            }
        }
        cout << dp[len - 1] << "\n";
    }
    return 0;
}
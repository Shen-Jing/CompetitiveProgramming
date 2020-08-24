#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <map>
#include <tuple>
#include <type_traits>
#include <utility>
#include <regex>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
};

class Solution
{
 public:
    string longestPalindrome(string input);
    pair<int, int> dp_palindrome(const string &str, vector<vector<bool>> &is_palin);
};

string Solution::longestPalindrome(string input)
{
    vector<vector<bool>> is_palin(input.length(), vector<bool>(input.length(), false));
    auto substr_idx = this->dp_palindrome(input, is_palin);
    auto substr_len = get<1>(substr_idx) - get<0>(substr_idx) + 1;
    return input.substr(get<0>(substr_idx), substr_len);
}

pair<int, int> Solution::dp_palindrome(const string &str, vector<vector<bool>> &is_palin)
{
    auto ans_idx = pair(0, 0);
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
            {
                is_palin[r][c] = (c - r == 1) || is_palin[r + 1][c - 1];
                if (is_palin[r][c] && (c - r) > (get<1>(ans_idx) - get<0>(ans_idx)))
                    ans_idx = std::pair(r, c);
            }
        }
    }
    return ans_idx;
}

int main(void)
{
    Solution ans;
    string input;
    while (cin >> input)
    {
        cout << ans.longestPalindrome(input);
    }
    return 0;
}
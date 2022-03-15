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
    string minRemoveToMakeValid(string s)
    {
    }

 private:
    string use_classical_stack(const string &s)
    {
        int len = s.length();
        /* Indices of open parenthesis */
        vector<int> open_idx;
        unordered_set<size_t> removed_indices;
        removed_indices.reserve(len >> 2);
        for (int i = 0; i < len; ++i)
        {
            if (s[i] == '(')
                open_idx.emplace_back(i);
            else if (s[i] == ')')
            {
                if (open_idx.empty())
                    removed_indices.emplace(i);
                else
                    open_idx.pop_back();
            }
        }

        for (const auto &i : open_idx)
            removed_indices.emplace(i);
        
        string valid_str;
        for (int i = 0; i < len; ++i)
            if (!removed_indices.count(i))
                valid_str += s[i];
        return valid_str;
    }

    string two_pass_and_reverse(string s)
    {
        s = remove_invalid_close_parenthesis(s);
        reverse(s.begin(), s.end());
        s = remove_invalid_close_parenthesis(s, {')', '('});
        reverse(s.begin(), s.end());
        return s;
    }

    string remove_invalid_close_parenthesis(const string &str, const pair<char, char> paren_pair = {'(', ')'})
    {
        auto len = str.length();
        vector<size_t> removed_indices;
        removed_indices.reserve(len >> 2);
        int balance{0};
        for (size_t i = 0; i < len; ++i)
        {
            if (str[i] == paren_pair.first)
                ++balance;
            else if (str[i] == paren_pair.second)
            {
                if (balance == 0)
                    removed_indices.emplace_back(i);
                else
                    --balance;
            }
        }
        removed_indices.emplace_back(len);

        string valid_str;
        auto removed_iter = removed_indices.begin();
        for (size_t i = 0; i < len; ++i)
        {
            if (i == *removed_iter)
                ++removed_iter;
            else
                valid_str += str[i];
        }
        return valid_str;
    }
};

int main(void)
{

    return 0;
}
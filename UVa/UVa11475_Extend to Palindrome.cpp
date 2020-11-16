#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
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

void set_failure_table(vector<int> &failure_table, const string &input)
{
    auto len = failure_table.size();
    for (int target_idx{1}, pattern_idx{-1}; target_idx < len; ++target_idx)
    {
        while (pattern_idx >= 0 && input[target_idx] != input[pattern_idx + 1])
            pattern_idx = failure_table[pattern_idx];
        if (input[target_idx] == input[pattern_idx + 1])
            ++pattern_idx;
        failure_table[target_idx] = pattern_idx;
    }
}

int main(void)
{
    string input;
    while (cin >> input)
    {
        auto reversed_input = input;
        reverse(reversed_input.begin(), reversed_input.end());

        /* Failure Table */
        vector<int> failure_table(reversed_input.length(), -1);
        set_failure_table(failure_table, reversed_input);

        /* Matching */
        auto target_len = input.length();
        auto is_match = false;
        int pattern_idx{-1};
        for (int target_cur_idx{0}; target_cur_idx < target_len; ++target_cur_idx)
        {
            while (pattern_idx >= 0 && input[target_cur_idx] != reversed_input[pattern_idx + 1])
                pattern_idx = failure_table[pattern_idx];
            if (input[target_cur_idx] == reversed_input[pattern_idx + 1])
                ++pattern_idx;
            
            if (pattern_idx + 1 == reversed_input.length())
            {
                is_match = true;
                break;
            }
        }

        cout << input;
        if (!is_match)
            cout << reversed_input.substr(pattern_idx + 1);
        cout << "\n";
    }

    return 0;
}
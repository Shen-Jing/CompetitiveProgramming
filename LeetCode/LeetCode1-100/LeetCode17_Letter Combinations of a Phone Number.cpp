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
    vector<string> letterCombinations(string digits)
    {
        n_ = digits.length();
        if (!n_)
            return ans_;
        digits_ = digits;
        backtrack(0, "");
        return ans_;
    }


 private:
    int n_;
    string digits_;
    vector<string> ans_;
    const unordered_map<int, string> digit_to_letters_
    {
      {2, "abc"},
      {3, "def"},
      {4, "ghi"},
      {5, "jkl"},
      {6, "mno"},
      {7, "pqrs"},
      {8, "tuv"},
      {9, "wxyz"},
    };

    void backtrack(int cur, string cur_combination)
    {
        if (cur == n_)
        {
            ans_.emplace_back(cur_combination);
            return;
        }
        
        auto cur_digit = digits_[cur] - '0';
        for (const auto &letter : digit_to_letters_.at(cur_digit))
        {
            cur_combination += letter;
            backtrack(cur + 1, cur_combination);
            cur_combination.pop_back();
        }
    }
};

int main(void)
{
    Solution sol;
    sol.letterCombinations("");
    sol.letterCombinations("23");
    return 0;
}
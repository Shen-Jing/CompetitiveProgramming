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
    int longestPalindromeSubseq(string s)
    {
        memo_.assign(s.length(), vector<int>(s.length(), 0));
        return LPS_top_down(s, 0, s.length() - 1);
    }

 private:
    vector<vector<int>> memo_;
    int LPS_top_down(const string &str, int left, int right)
    {
        if (left > right)
            return 0;
        if (left == right)
            return 1;

        auto &memo_ref = memo_[left][right];
        if (memo_ref)
            return memo_ref;
        if (str[left] == str[right])
            return memo_ref = 2 + LPS_top_down(str, left + 1, right - 1);
        return memo_ref = max(LPS_top_down(str, left, right - 1), LPS_top_down(str, left + 1, right));
    }
};

int main(void)
{

    return 0;
}
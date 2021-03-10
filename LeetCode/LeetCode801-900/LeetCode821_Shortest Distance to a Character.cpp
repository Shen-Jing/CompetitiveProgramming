#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <vector>

static auto io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
  public:
      std::vector<int> shortestToChar(std::string S, char C) {
        std::vector<int> ans(S.size(), std::numeric_limits<int>::max());
        std::vector<int> vec_pos;
        // record 'char' position
        for (auto  i = 0; i < S.size(); ++i)
            if (S[i] == C)
                vec_pos.emplace_back(i);
        // find min
        for (auto i = 0; i < S.size(); ++i)
        {
            for (auto & pos : vec_pos)
            {
                auto dist = std::abs(pos - i);
                if (dist > ans[i])
                    break;
                ans[i] = dist;
            }
        }
        return ans;
    }
};

int main(void)
{
    Solution sol;
    auto tmp = sol.shortestToChar("loveleetcode", 'e');
    std::copy(tmp.begin(), tmp.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}

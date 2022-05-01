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
    int countPrefixes(vector<string>& words, string s)
    {
        unordered_set<string> prefix_set;
        int len = s.length();
        for (int end = 0; end < len; ++end)
        {
            prefix_set.emplace(s.substr(0, end + 1));
        }

        int cnt{0};
        for (const auto &w : words)
        {
            if (prefix_set.count(w))
                ++cnt;
        }
        return cnt;
    }
};

int main(void)
{

    return 0;
}
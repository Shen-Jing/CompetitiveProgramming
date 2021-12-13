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
    int maxPower(string s)
    {
        int cur_cnt{1}, max_cnt{1};
        for (size_t i = 1; i < s.size(); ++i)
        {
            if (s[i] != s[i - 1])
                cur_cnt = 1;
            else
                ++cur_cnt;
            max_cnt = max(max_cnt, cur_cnt);
        }
        return max_cnt;
    }

 private:
};

int main(void)
{

    return 0;
}
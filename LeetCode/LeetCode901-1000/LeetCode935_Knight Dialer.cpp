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
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
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
    Solution()
    {
        _cnt = 0;
        _transitions = {
          {4, 6},
          {6, 8},
          {7, 9},
          {4, 8},
          {3, 9},
          {},
          {1, 7},
          {2, 6},
          {1, 3},
          {2, 4}
        };
    }

    int knightDialer(int n)
    {
        return brute_force(n);
    }

 private:
    vector<vector<int>> _transitions;
    int _cnt;
    int brute_force(int n)
    {
        for (int start_num = 0; start_num <= 9; ++start_num)
        {
            _cnt += enumerates(start_num, n);
        }
        return _cnt;
    }

    int enumerates(int start_num, int length)
    {
        if (length == 1)
            return 1;
        int cnt = 0;
        for (const auto &next_num : _transitions[start_num])
        {
            cnt += enumerates(next_num, length - 1) % (1000000007);
        }
        return cnt;
    }
};

int main(void)
{
    Solution sol;
    sol.knightDialer(2);
    return 0;
}
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
          {0, 3, 9},
          {},
          {0, 1, 7},
          {2, 6},
          {1, 3},
          {2, 4}
        };
        for (auto &row : _states)
        {
            row.fill(-1);
        }
    }

    int knightDialer(int n)
    {
        return brute_force(n);
    }

 private:
    vector<vector<int>> _transitions;
    array<array<long long, 5001>, 10> _states;
    int _MOD = 1e9 + 7;
    long long _cnt;
    int brute_force(int n)
    {
        for (int start_num = 0; start_num <= 9; ++start_num)
        {
            /// 🙅‍♂️ old + new % _MOD
            _cnt = (_cnt + enumerates(start_num, n)) % _MOD;
        }
        return _cnt;
    }

    long long enumerates(int start_num, int length)
    {
        if (_states[start_num][length] != -1)
            return _states[start_num][length];
        if (length == 1)
            return _states[start_num][length] = 1;
        long long cnt = 0;
        for (const auto &next_num : _transitions[start_num])
        {
            cnt = (cnt + enumerates(next_num, length - 1)) % _MOD;
        }
        return _states[start_num][length] = cnt;
    }
};

int main(void)
{
    Solution sol;
    sol.knightDialer(2);
    sol.knightDialer(31);
    return 0;
}
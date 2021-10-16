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
    bool winnerOfGame(string colors)
    {
        return smarter_simulate(colors);
    }

    /* Brute Force */
    bool simulate(string colors)
    {
        char target = 'A';
        bool finished{false};
        while (true)
        {
            for (int i = 1; i <= static_cast<int>(colors.length()) - 2; ++i)
            {
                if (try_to_remove(colors, i, target))
                {
                    finished = true;
                    break;
                }
            }
            if (!finished)
                return (target == 'B') ? true : false;
            target = (target == 'A') ? 'B' : 'A';
            finished = false;
        }
    }

    /* Brute Force 2 */
    bool smarter_simulate(string colors)
    {
        char target = 'A';
        bool finished{false};
        while (true)
        {
            auto found_pos = colors.find(string(3, target));
            if (found_pos == string::npos)
                return (target == 'B') ? true : false;
            else
            {
                colors.erase(found_pos, 1);
                target = (target == 'A') ? 'B' : 'A';
            }
        }
    }

 private:
    bool try_to_remove(string &colors, const size_t &idx, const char &target)
    {
        if (
            colors[idx - 1] == target && 
            colors[idx] == target &&
            colors[idx + 1] == target
           )
        {
            colors.erase(idx, 1);
            return true;
        }
        return false;
    }
};

int main(void)
{
    Solution sol;

    cout << sol.winnerOfGame(string("A"));
    cout << sol.winnerOfGame(string("AAABABB"));

    return 0;
}
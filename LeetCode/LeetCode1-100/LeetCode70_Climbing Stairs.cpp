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
    int climbStairs(int n)
    {
        num_of_ways.fill(-1);
        num_of_ways[0] = 0;
        num_of_ways[1] = 1;
        num_of_ways[2] = 2;
        return climb_recursive(n);
    }

 private:
    /* invalid use of non-static data member */
    static const int max_steps = 45 + 1;
    array<int, max_steps> num_of_ways;
    int climb_recursive(int n)
    {
        if (num_of_ways[n] != -1)
            return num_of_ways[n];
        return num_of_ways[n] = climb_recursive(n - 1) + climb_recursive(n - 2);
    }

    /* Written in 2019 */
    int climb_bottom_up(int n)
    {
        std::vector<int> sol{0, 1, 2};
        for (int i = 3; i <= n; ++i)
        {
            sol.emplace_back(sol[i - 1] + sol[i - 2]);
        }
        return sol[n];            
    }
};

int main(void)
{

    return 0;
}
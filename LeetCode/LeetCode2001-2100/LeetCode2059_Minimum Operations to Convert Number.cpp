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
    int minimumOperations(vector<int> &nums, int start, int goal)
    {
        /* {current number, the number of operations} */
        queue<pair<int, int>> Q;
        Q.emplace(make_pair(start, 0));
        unordered_set<int> seen{start};
        while (!Q.empty())
        {
            const auto [curr_num, curr_opers] = Q.front();
            Q.pop();

            const int num_opers = curr_opers + 1;
            for (const auto &num : nums)
            {
                for (const auto oper : {'+', '-', '^'})
                {
                    int nxt_num;
                    if (oper == '+')
                        nxt_num = curr_num + num;
                    else if (oper == '-')
                        nxt_num = curr_num - num;
                    else if (oper == '^')
                        nxt_num = curr_num ^ num;
                    
                    if (nxt_num == goal)
                        return num_opers;
                    if (nxt_num < 0 || nxt_num > 1000 || seen.count(nxt_num))
                        continue;

                    seen.emplace(nxt_num);
                    Q.emplace(make_pair(nxt_num, num_opers));
                }
            }
        }
        return -1;
    }
};

int main(void)
{
    Solution sol;

    vector<int> nums{3, 5, 7};
    // sol.minimumOperations(nums, 0, -4);

    // nums = {2, 4, 12};
    // sol.minimumOperations(nums, 2, 12);

    nums = {2, 8, 16};
    cout << sol.minimumOperations(nums, 0, 1) << endl;

    return 0;
}
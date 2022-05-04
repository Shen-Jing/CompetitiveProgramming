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
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
    }

 private:
    int my_dp(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        vector<vector<int>> jobs;
        int sz = profit.size();
        for (int i = 0; i < sz; ++i)
        {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());

        vector<int> max_profits(sz, 0);
        int max_profit = 0;
        for (int i = 0; i < sz; ++i)
        {
            /* The current max profit */
            max_profits[i] = jobs[i][2];
            for (int j = 0; j < i; ++j)
            {
                if (jobs[i][0] >= jobs[j][1])
                    max_profits[i] = max(max_profits[i], jobs[i][2] + max_profits[j]);
            }
            max_profit = max(max_profit, max_profits[i]);
        }
        return max_profit;
    }
};

int main(void)
{

    return 0;
}
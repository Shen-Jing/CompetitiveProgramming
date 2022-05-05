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
        return top_down(startTime, endTime, profit);
    }

 private:
    vector<int> max_profits;
    int find_max_profit_top_down(vector<vector<int>> &jobs, int i)
    {
        if (i == jobs.size())
            return 0;
        if (max_profits[i] != -1)
            return max_profits[i];
        
        int nxt_idx = lower_bound(jobs.begin(), jobs.end(), jobs[i][1],
            [](const auto &ele, int end_time)
            {
                return ele[0] < end_time;
            }) - jobs.begin();
        /* Skip the current job or not */
        max_profits[i] = max(find_max_profit_top_down(jobs, i + 1), 
                             find_max_profit_top_down(jobs, nxt_idx) + jobs[i][2]);
        return max_profits[i];
    }

    int top_down(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        vector<vector<int>> jobs;
        int sz = profit.size();
        for (int i = 0; i < sz; ++i)
        {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());

        max_profits.assign(sz, -1);
        return find_max_profit_top_down(jobs, 0);
    }
};

int main(void)
{
    Solution sol;
    vector<int> startTime, endTime, profit;

    startTime = {1,2,3,3};
    endTime = {3,4,5,6};
    profit = {50,10,40,70};
    sol.jobScheduling(startTime, endTime, profit);

    return 0;
}
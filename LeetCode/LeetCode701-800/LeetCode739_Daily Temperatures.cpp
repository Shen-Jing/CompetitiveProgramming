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
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        return use_prev_ans_info(temperatures);
    }

 private:
    vector<int> use_prev_ans_info(const vector<int> &temperatures)
    {
        auto sz = temperatures.size();
        vector<int> ans(sz, 0);
        int hottest_val{0};
        for (int cur_day = sz - 1; cur_day >= 0; --cur_day)
        {
            if (temperatures[cur_day] >= hottest_val)
            {
                hottest_val = temperatures[cur_day];
                continue;
            }

            int days{1};
            while (temperatures[cur_day + days] <= temperatures[cur_day])
            {
                days += ans[cur_day + days];
            }
            ans[cur_day] = days;
        }
        return ans;
    }
};

int main(void)
{
    Solution sol;

    vector<int> data{45, 43, 45, 43, 45, 31, 32, 33, 50};
    sol.dailyTemperatures(data);

    return 0;
}
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
    int maxProfit(vector<int>& prices)
    {
        return one_pass(prices);
    }

 private:
    int brute_force(vector<int>& prices)
    {
        auto sz = prices.size();
        int max_profit{0};
        for (size_t i = 0; i < sz - 1; ++i)
        {
            auto max_price = *max_element(prices.begin() + i + 1, prices.end());
            max_profit = max(max_profit, max_price - prices[i]);
        }
        return max_profit;
    }
    
    int one_pass(const vector<int> &prices)
    {
        int max_profit{0}, min_price = numeric_limits<int>::max();
        for (const auto &price : prices)
        {
            min_price = min(min_price, price);
            max_profit = max(max_profit, price - min_price);
        }
        return max_profit;
    }
};

int main(void)
{
    Solution sol;
    vector<int> prices{7,1,5,3,6,4};

    sol.maxProfit(prices);
    return 0;
}
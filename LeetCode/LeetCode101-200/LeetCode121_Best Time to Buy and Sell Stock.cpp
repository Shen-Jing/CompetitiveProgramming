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
        auto sz = prices.size();
        int max_profit{0};
        for (size_t i = 1; i < sz; ++i)
        {
            auto max_price = *max_element(prices.begin() + i + 1, prices.end());
            max_profit = max(max_profit, max_price - prices[i]);
        }
        return max_profit;
    }
};

int main(void)
{

    return 0;
}
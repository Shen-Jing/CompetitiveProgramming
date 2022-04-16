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
    int coinChange(vector<int>& coins, int amount)
    {
        min_coins_.assign(amount + 1, numeric_limits<int>::max());
        top_down(coins, amount);
        return (min_coins_[amount] == numeric_limits<int>::max()) ? -1 : min_coins_[amount];
    }

    int top_down(const vector<int> &coins, int amount)
    {
        if (amount < 0)
            return -1;
        if (min_coins_[amount] != numeric_limits<int>::max())
            return min_coins_[amount];
        if (amount == 0)
            return min_coins_[amount] = 0;

        for (const auto &coin : coins)
        {
            if (top_down(coins, amount - coin) != -1)
                min_coins_[amount] = min(min_coins_[amount], min_coins_[amount - coin] + 1);
        }
        if (min_coins_[amount] == numeric_limits<int>::max())
            min_coins_[amount] = -1;
        return min_coins_[amount];
    }
 private:
    vector<int> min_coins_;
};

int main(void)
{
    Solution sol;

    vector<int> coins;

    coins = {2, 5, 10, 1};
    cout << sol.coinChange(coins, 27) << "\n";

    return 0;
}
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
        backtrack(coins, 0, amount, 0);
        return ans_;
    }

    void backtrack(const vector<int> &coins, int coin_idx, int target_amount, int num_of_coins)
    {
        if (target_amount < 0)
        {
            ans_ = (ans_ == numeric_limits<int>::max()) ? -1 : ans_;
            return;
        }
        if (target_amount == 0)
        {
            ans_ = (ans_ == -1) ? num_of_coins : min(ans_, num_of_coins);
            return;
        }

        ++num_of_coins;
        for (int i = coin_idx; i < coins.size(); ++i)
        {
            backtrack(coins, i, target_amount - coins[i], num_of_coins);
        }
    }
 private:
    int ans_ = numeric_limits<int>::max();
};

int main(void)
{
    Solution sol;

    vector<int> coins;

    coins = {2, 5, 10, 1};
    cout << sol.coinChange(coins, 27) << "\n";

    return 0;
}
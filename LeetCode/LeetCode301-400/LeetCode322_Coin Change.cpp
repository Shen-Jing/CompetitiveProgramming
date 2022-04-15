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
        recursive(coins, amount, 0, 0, 0);
        return ans_;
    }

    void recursive(const vector<int> &coins, const int amount, int curr_amount, size_t coin_idx, int num_of_coins)
    {
        if (coin_idx == coins.size())
            return;
        if (curr_amount + coins[coin_idx] == amount)
            ans_ = num_of_coins + 1;
        else if (curr_amount + coins[coin_idx] > amount)
            recursive(coins, amount, curr_amount, coin_idx + 1, num_of_coins);
        else if (curr_amount + coins[coin_idx] < amount)
        {
            recursive(coins, amount, curr_amount, coin_idx + 1, num_of_coins);
            recursive(coins, amount, curr_amount + coins[coin_idx], coin_idx, num_of_coins + 1);
        }
    }
 private:
    int ans_ = 0;
};

int main(void)
{

    return 0;
}
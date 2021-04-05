#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <tuple>
#include <type_traits>
#include <utility>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <type_traits>
#include <vector>

using namespace std;

static auto io = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

int budget, num_garment, num_model;
auto garment_price = vector<vector<int>>();
auto dp = vector<vector<bool>>();

void shop(int cur_garment, int cur_budget)
{
    if (cur_garment > num_garment)
        return;
    for (const auto &price : garment_price[cur_garment])
    {
        if (dp[cur_garment - 1][cur_budget] && cur_budget >= price)
        {
            dp[cur_garment][cur_budget - price] = true;
            shop(cur_garment + 1, cur_budget - price);
        }
    }

}

int main(void)
{
    int kase;
    cin >> kase;
    for (int k = 0; k < kase; ++k)
    {
        cin >> budget >> num_garment;

        garment_price.assign(num_garment + 1, vector<int>());
        for (int g = 1; g <= num_garment; ++g)
        {
            cin >> num_model;
            garment_price[g].reserve(num_model);
            for (int m = 0; m < num_model; ++m)
            {
                int price;
                cin >> price;
                garment_price[g].emplace_back(price);
            }
        }

        /* Initialization */
        dp.assign(num_garment + 1, vector<bool>(budget + 1, false));
        fill(dp[0].begin(), dp[0].end(), true);

        /* Compute & Output */
        shop(1, budget);
        auto remaining = 0;
        for ( ; remaining <= budget; ++remaining)
        {
            if (dp[num_garment][remaining])
            {
                cout << budget - remaining << "\n";
                break;
            }
        }
        if (remaining > budget)
            cout << "no solution\n";
        // traceback(dp, garment_price);
    }
    return 0;
}
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

int main(void)
{
    int kase, budget, num_garment, num_model;
    cin >> kase;
    for (int k = 0; k < kase; ++k)
    {
        cin >> budget >> num_garment;

        auto garment_price = vector<vector<int>>(num_garment + 1, vector<int>());
        auto dp = vector<vector<int>>(num_garment + 1, vector<int>(budget + 1, 0));

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

        for (int g_idx = 1; g_idx <= num_garment; ++g_idx)
        {
            for (int cur_budget = 1; cur_budget <= budget; ++cur_budget)
            {
                for (int m = 0; m < garment_price[g_idx].size(); ++m)
                {
                    if (garment_price[g_idx][m] > cur_budget)
                        continue;
                    if (dp[g_idx][cur_budget] < dp[g_idx - 1][cur_budget - garment_price[g_idx][m]] + garment_price[g_idx][m])
                        dp[g_idx][cur_budget] = dp[g_idx - 1][cur_budget - garment_price[g_idx][m]] + garment_price[g_idx][m];
                }
            }
        }

        // traceback(dp, garment_price);
        cout << dp[num_garment][budget] << "\n";
    }
    return 0;
}
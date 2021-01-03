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

int num_of_cuts;
vector<vector<int>> dp;
vector<int> places;

int solve(int start, int end)
{
    if (end - start == 1)
    {
        dp[start][end] = places[end] - places[start];
        return dp[start][end];
    }
    
    int min_cost{numeric_limits<int>::max()};
    for (int cut_place = 1; cut_place < num_of_cuts; ++cut_place)
    {
        int cost_of_this_cut = (places[end] - places[start]) + solve(start, cut_place) + solve(cut_place, end);
        if (cost_of_this_cut < min_cost)
        {
            min_cost = cost_of_this_cut;
            // (places[end] - places[start]) + dp[start][cut_place] + dp[cut_place][end];
        }
    }
    dp[start][end] = min_cost;
    return min_cost;
}

int main(void)
{
    int stick_len;
    while (cin >> stick_len)
    {
        cin >> num_of_cuts;
        places.assign({0});
        places.reserve(num_of_cuts + 2);  // plus "start" (0) & "end"
        for (int i = 0; i < num_of_cuts; ++i)
        {
            int place;
            cin >> place;
            places.emplace_back(place);
        }
        places.emplace_back(stick_len);

        dp.assign(num_of_cuts, vector<int>(num_of_cuts + 1, 0));
        solve(0, num_of_cuts + 1);
    }

    return 0;
}
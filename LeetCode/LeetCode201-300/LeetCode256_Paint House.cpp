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
    int minCost(vector<vector<int>> &costs)
    {
        int num_of_houses = costs.size(),
            min_cost = numeric_limits<int>::max();
        min_costs_.assign(num_of_houses, vector<int>(num_of_colors_, numeric_limits<int>::max()));
        for (int c{0}; c < num_of_colors_; ++c)
            min_cost = min(min_cost, top_down(costs, num_of_houses - 1, c));
        return min_cost;
    }

 private:
    const int num_of_colors_{3};
    vector<vector<int>> min_costs_;
    int top_down(const vector<vector<int>> &costs, int curr_house, int curr_color)
    {
        if (min_costs_[curr_house][curr_color] != numeric_limits<int>::max())
            return min_costs_[curr_house][curr_color];
        if (curr_house == 0)
            return min_costs_[curr_house][curr_color] = costs[curr_house][curr_color];
        for (int c{0}; c < num_of_colors_; ++c)
        {
            if (c != curr_color)
                min_costs_[curr_house][curr_color] = min(min_costs_[curr_house][curr_color],
                                                        top_down(costs, curr_house - 1, c));
        }
        return min_costs_[curr_house][curr_color] += costs[curr_house][curr_color];
    }
};

int main(void)
{

    return 0;
}
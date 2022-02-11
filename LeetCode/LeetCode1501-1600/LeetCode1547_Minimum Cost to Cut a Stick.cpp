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
    int minCost(int n, vector<int> &cuts)
    {
        return top_down(n, cuts);
    }

 private:
    vector<vector<int>> costs_;
    int top_down(int n, const vector<int> &cuts)
    {
        costs_.assign(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));
        return cut(cuts, 0, n);
    }

    int cut(const vector<int> &cuts, int left, int right)
    {
        if (right <= left + 1)
            return 0;
        if (costs_[left][right] != numeric_limits<int>::max())
            return costs_[left][right];
        for (const auto &cut_pos : cuts)
        {
            if (cut_pos <= left || cut_pos >= right)
                continue;
            costs_[left][right] = min(costs_[left][right], 
                                      (right - left) + cut(cuts, left, cut_pos) + cut(cuts, cut_pos, right));
        }
        return (costs_[left][right] == numeric_limits<int>::max()) ? (right - left) : costs_[left][right];
    }
};

int main(void)
{
    Solution sol;
    
    vector<int> cuts{1, 3, 4, 5};
    sol.minCost(7, cuts);

    return 0;
}
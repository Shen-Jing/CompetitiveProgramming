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
    int top_down(int n, vector<int> &cuts)
    {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.emplace_back(n);
        costs_.assign(cuts.size(), vector<int>(cuts.size(), numeric_limits<int>::max()));
        return cut(cuts, 0, cuts.size() - 1);
    }

    /* left, right: index of cuts */
    int cut(const vector<int> &cuts, int left, int right)
    {
        if (right <= left + 1)
            return 0;
        if (costs_[left][right] != numeric_limits<int>::max())
            return costs_[left][right];
        for (int cut_idx = left + 1; cut_idx < right; ++cut_idx)
        {
            costs_[left][right] = min(costs_[left][right], 
                                      (cuts[right] - cuts[left]) + cut(cuts, left, cut_idx) + cut(cuts, cut_idx, right));
        }
        return costs_[left][right];
    }
};

int main(void)
{
    Solution sol;
    
    vector<int> cuts{1, 3, 4, 5};
    sol.minCost(7, cuts);

    return 0;
}
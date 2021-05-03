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
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        ans_.reserve(150);  // Problem's guarantee
        vector<int> cur_combination;
        combination_sum_backtrack(candidates, 0, cur_combination, 0, target);
        return ans_;
    }

 private:
    vector<vector<int>> ans_;

    void combination_sum_backtrack(const vector<int> &candidates, int cur_idx, vector<int> &cur_comb, int cur_sum, const int &target)
    {
        if (cur_sum == target)
        {
            ans_.emplace_back(cur_comb);
            return;
        }
        if (cur_idx == candidates.size())
            return;

        auto old_sum = cur_sum;
        auto old_comb = cur_comb;
        while (cur_sum + candidates[cur_idx] <= target)
        {
            cur_comb.emplace_back(candidates[cur_idx]);
            cur_sum += candidates[cur_idx];
            combination_sum_backtrack(candidates, cur_idx + 1, cur_comb, cur_sum, target);
        }

        /* Restoring state */
        cur_sum = old_sum;
        cur_comb = old_comb;
        combination_sum_backtrack(candidates, cur_idx + 1, cur_comb, cur_sum, target);
    }
};

int main(void)
{
    Solution sol;

    vector<int> candidates{2, 3, 6, 7};
    sol.combinationSum(candidates, 7);

    return 0;
}
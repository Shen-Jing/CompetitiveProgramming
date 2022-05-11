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
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        int sum{0};
        vector<int> comb;
        comb_backtrack(candidates, comb, 0, sum, target);
        return vector<vector<int>>(ans_.begin(), ans_.end());
    }

 private:
    set<vector<int>> ans_;
    void comb_backtrack(vector<int>& candidates, vector<int> &cur_comb, int cur_idx, int &cur_sum, const int &target)
    {
        if (cur_sum == target)
        {
            ans_.emplace(cur_comb);
            return;
        }
        if (cur_sum > target || cur_idx == candidates.size())
            return;

        for (int i = cur_idx; i < candidates.size(); ++i)
        {
            cur_comb.emplace_back(candidates[i]);
            cur_sum += candidates[i];
            comb_backtrack(candidates, cur_comb, i + 1, cur_sum, target);
            cur_comb.pop_back();
            cur_sum -= candidates[i];
        }
    }
};

int main(void)
{
    Solution sol;
    vector<int> candidates;

    candidates = {1,1,2,6};
    sol.combinationSum2(candidates, 8);

    return 0;
}
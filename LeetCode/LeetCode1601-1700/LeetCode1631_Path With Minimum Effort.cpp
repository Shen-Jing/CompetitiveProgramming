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
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        rows_ = heights.size();
        cols_ = heights[0].size();
        visited_.assign(rows_, vector<bool>(cols_, false));
        // min_efforts_.assign(rows_, vector<int>(cols_, numeric_limits<int>::max()));
        int effort{0};
        brute_force_backtrack(heights, 0, 0, effort);
        return ans_;
    }

 private:
    int rows_, cols_, 
        ans_ = numeric_limits<int>::max();
    array<array<int, 2>, 4> dirs_{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    vector<vector<int>> min_efforts_;
    vector<vector<bool>> visited_;
    bool is_out_of_bound(const int &r, const int &c)
    {
        if (r < 0 || c < 0 ||
            r >= rows_ || c >= cols_)
            return true;
        return false;
    }

    void brute_force_backtrack(const vector<vector<int>> &heights, int cur_r, int cur_c, int &cur_effort)
    {
        if (cur_r == rows_ - 1 && cur_c == cols_ - 1)
        {
            ans_ = min(ans_, cur_effort);
            return;
        }
        visited_[cur_r][cur_c] = true;
        for (const auto &dir : dirs_)
        {
            int nxt_r = cur_r + dir[0],
                nxt_c = cur_c + dir[1];
            if (is_out_of_bound(nxt_r, nxt_c) || visited_[nxt_r][nxt_c])
                continue;
            int old_effort = cur_effort;
            cur_effort = max(cur_effort, abs(heights[nxt_r][nxt_c] - heights[cur_r][cur_c]));
            brute_force_backtrack(heights, nxt_r, nxt_c, cur_effort);
            cur_effort = old_effort;
        }
        visited_[cur_r][cur_c] = false;
    }
};

int main(void)
{

    return 0;
}

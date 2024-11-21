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
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        rows_ = heights.size();
        cols_ = heights[0].size();
        memo_.assign(rows_, vector<int>(cols_, -1));
        for (int r = 0; r < rows_; ++r)
            for (int c = 0; c < cols_; ++c)
                by_DFS(heights, r, c);
        return ans_;
    }

 private:
    int rows_, cols_;
    array<array<int, 2>, 4> dirs{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};  // North, South, West, East
    vector<vector<int>> memo_;  // -1: not visited; 0: visited but cannot reach ocean; 1: top & left; 2 down & right; 3: both
    vector<vector<int>> ans_;
    bool by_DFS(const vector<vector<int>> &heights, int cur_r, int cur_c)
    {
        if (memo_[cur_r][cur_c] == 3)
            return true;
        if (memo_[cur_r][cur_c] != -1)
            return false;
        memo_[cur_r][cur_c] = 0;
        for (const auto &dir : dirs)
        {
            int new_r = cur_r + dir[0],
                new_c = cur_c + dir[1];
            if (new_r < 0 || new_c < 0) 
            {
                if (memo_[cur_r][cur_c] == 1)
                    continue;
                if (memo_[cur_r][cur_c] == 2)
                {
                    memo_[cur_r][cur_c] = 3;
                    ans_.push_back({cur_r, cur_c});
                    continue;
                }
                memo_[cur_r][cur_c] = 1;
            }
            else if (new_r == rows_ || new_c == cols_)
            {
                if (memo_[cur_r][cur_c] == 2)
                    continue;
                if (memo_[cur_r][cur_c] == 1)
                {
                    memo_[cur_r][cur_c] = 3;
                    ans_.push_back({cur_r, cur_c});
                    continue;
                }
                memo_[cur_r][cur_c] = 2;
            }
            else if (heights[cur_r][cur_c] >= heights[new_r][new_c] && by_DFS(heights, new_r, new_c))
            {
                memo_[cur_r][cur_c] = 3;
                ans_.push_back({cur_r, cur_c});
                return true;
            }
        }
        return (memo_[cur_r][cur_c] == 3);
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> heights;
    
    heights = {{2, 1}, {3, 4}, {5, 6}};
    sol.pacificAtlantic(heights);

    heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    sol.pacificAtlantic(heights);

    return 0;
}
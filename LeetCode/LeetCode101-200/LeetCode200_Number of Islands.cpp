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
    int numIslands(vector<vector<char>> &grid) 
    {
        rows_ = grid.size();
        cols_ = grid[0].size();
        visited_.assign(rows_, vector<bool>(cols_, false));
        int num_of_islands = 0;
        for (int r = 0; r < rows_; ++r)
            for (int c = 0; c < cols_; ++c)
            {
                if (grid[r][c] == '1' && !visited_[r][c])
                    dfs(grid, r, c, num_of_islands++);
            }
        return num_of_islands;
    }

 private:
    vector<vector<bool>> visited_;
    int rows_, cols_;
    array<array<int, 2>, 4> dirs{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};

    bool is_out_of_bound(int r, int c)
    {
        if (r < 0 || c < 0 ||
            r >= rows_ || c >= cols_)
            return true;
        return false;
    }

    void dfs(const vector<vector<char>> &grid, int r, int c, int island_id)
    {
        visited_[r][c] = true;
        for (const auto &dir : dirs)
        {
            int next_r = r + dir[0],
                next_c = c + dir[1];
            if (is_out_of_bound(next_r, next_c) || visited_[next_r][next_c] || grid[next_r][next_c] == '0')
                continue;
            dfs(grid, next_r, next_c, island_id);
        }
    }
};

int main(void)
{
    Solution sol;

    vector<vector<char>> grid{{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    sol.numIslands(grid);

    return 0;
}
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

struct Cell
{
  int row;
  int col;
  int rotten_time;
  Cell(int r, int c, int t) : row(r), col(c), rotten_time(t) {}
};

array<array<int, 2>, 4> dirs{ {{-1, 0}, {1, 0}, {0, -1}, {0, 1}} };

class Solution
{
 public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        /* Init */
        rows_ = grid.size();
        cols_ = grid[0].size();
        return propagate_BFS(grid);
    }

    int propagate_BFS(vector<vector<int>>& grid)
    {
        queue<Cell> q;
        for (int r = 0; r < rows_; ++r)
            for (int c = 0; c < cols_; ++c)
                if (grid[r][c] == 2)
                    q.emplace(Cell(r, c, 0));
        /* BFS */
        int minutes{0};
        while (!q.empty())
        {
            const auto cur_cell = q.front();
            const auto cur_time = cur_cell.rotten_time;
            q.pop();
            for (const auto &dir : dirs)
            {
                const auto next_row = cur_cell.row + dir[0],
                           next_col = cur_cell.col + dir[1];
                if (!is_out_of_bound(next_row, next_col) && grid[next_row][next_col] == 1)
                {
                    grid[next_row][next_col] = 2;
                    q.emplace(Cell(next_row, next_col, cur_time + 1));
                    minutes = max(minutes, cur_time + 1);
                }
            }
        }

        for (int r = 0; r < rows_; ++r)
            for (int c = 0; c < cols_; ++c)
                if (grid[r][c] == 1)
                    return -1; 
        return minutes;
    }

 private:
    int rows_, cols_;
    bool is_out_of_bound(int row, int col)
    {
        if (row >= rows_ || col >= cols_ ||
            row < 0 || col < 0)
            return true;
        return false;
    }
};

int main(void)
{

    return 0;
}
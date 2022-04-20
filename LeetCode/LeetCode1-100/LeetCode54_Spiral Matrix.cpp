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
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        rows_ = matrix.size();
        cols_ = matrix.front().size();
        visited_.assign(rows_, vector<bool>(cols_, false));
        DFS_spiral_traverse(matrix, 0, 0);
        return ans_;
    }

 private:
    int rows_, cols_;
    array<array<int, 2>, 4> dirs_{{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}};
    vector<vector<bool>> visited_;
    vector<int> ans_;
    bool is_out_of_bound(const int &row, const int &col)
    {
        if (row >= rows_ || col >= cols_ ||
            row < 0 || col < 0)
            return true;
        return false;
    }

    void DFS_spiral_traverse(const vector<vector<int>> &matrix, const int &cur_row, const int &cur_col)
    {
        visited_[cur_row][cur_col] = true;
        ans_.emplace_back(matrix[cur_row][cur_col]);
        for (const auto &dir : dirs_)
        {
            int nxt_row = cur_row + dir[0], 
                nxt_col = cur_col + dir[1];
            if (!is_out_of_bound(nxt_row, nxt_col) && !visited_[nxt_row][nxt_col])
            {
                DFS_spiral_traverse(matrix, nxt_row, nxt_col);
                return;
            }
        }
    }
};

int main(void)
{

    return 0;
}
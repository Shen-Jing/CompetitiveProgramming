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
#include <stack>
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
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        if (matrix.empty())
            return 0;
        row_size = matrix.size();
        col_size = matrix[0].size();
        auto length_memo = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        int longest_len = 0;
        for (size_t r = 0; r < row_size; ++r)
            for (size_t c = 0; c < col_size; ++c)
            {
                longest_len = max(longest_len, 1 + dfs(matrix, r, c, length_memo));
            }
        return longest_len;
    }

 private:
    int row_size, col_size;
    bool check_valid_boundary(int r, int c)
    {
        if (r < 0 || c < 0 ||
            r >= row_size || c >= col_size)
            return false;
        return true;
    }

    int dfs(const vector<vector<int>>& matrix, const int &cur_row, const int &cur_col, vector<vector<int>> &length_memo)
    {
        if (length_memo[cur_row][cur_col])
            return length_memo[cur_row][cur_col];

        array<int, 3> dir{-1, 0, 1};
        int max_len = 0;
        for (const auto &row_offset : dir)
            for (const auto &col_offset : dir)
            {
                const auto next_row = cur_row + row_offset, 
                           next_col = cur_col + col_offset;

                /* No diagonal && visited */
                if (row_offset == col_offset ||
                    !check_valid_boundary(next_row, next_col) ||
                    matrix[next_row][next_col] <= matrix[cur_row][cur_col])
                    continue;
                max_len = dfs(matrix, next_row, next_col, length_memo);
            }
        return length_memo[cur_row][cur_col] = max_len;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> matrix{{3,4,5}, {3,2,6}, {2,2,1}};
    cout << sol.longestIncreasingPath(matrix) << "\n";
    matrix = {{9,9,4}, {6,6,8}, {2,1,1}};
    cout << sol.longestIncreasingPath(matrix) << "\n";
    return 0;
}
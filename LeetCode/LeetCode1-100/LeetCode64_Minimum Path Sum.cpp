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
    void init(vector<vector<int>>& grid)
    {
        k_rows = grid.size();
        k_cols = grid[0].size();
    }

    int minPathSum(vector<vector<int>>& grid) 
    {
        init(grid);
        return top_down_recursive(grid, k_rows - 1, k_cols - 1);
    }

 private:
    int k_rows, k_cols;
    const array<pair<int, int>, 2> dirs{make_pair(-1, 0), make_pair(0, -1)};

    bool is_out_of_bound(int r, int c)
    {
        if (r < 0 || c < 0)
            return true;
        return false;
    }

    int top_down_recursive(const vector<vector<int>> &grid, int r, int c)
    {
        if (!r && !c)
            return grid[r][c];
        
        int min_sum = numeric_limits<int>::max();
        for (const auto &dir : dirs)
        {
            const auto new_r = r + dir.first, 
                       new_c = c + dir.second;
            if (is_out_of_bound(new_r, new_c))
                continue;
            min_sum = min(min_sum, 
                          grid[r][c] + top_down_recursive(grid, new_r, new_c)
                         );
        }
        return min_sum;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> grid{{1,3,1}, {1,5,1}, {4,2,1}};
    cout << sol.minPathSum(grid) << "\n";

    return 0;
}
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
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        vector<vector<bool>> valid_pos(m, vector<bool>(n, true));
        set<pair<int, int>> walls_set, guards_set;
        /* Mark walls (invalid) */
        for (const auto &w : walls)
        {
            valid_pos[w[0]][w[1]] = false;
            walls_set.insert({w[0], w[1]});
        }
        /* Mark guards (invalid) */
        for (const auto &g : guards)
        {
            valid_pos[g[0]][g[1]] = false;
            guards_set.insert({g[0], g[1]});
        }

        /* Mark guard vision */
        for (const auto &g : guards)
        {
            int r = g[0], c = g[1];
            /* (north, south, east, or west) */
            for (int r_i = r - 1; r_i >= 0; --r_i)
            {
                if (walls_set.count({r_i, c}) || guards_set.count({r_i, c}))
                    break;
                valid_pos[r_i][c] = false;
            }
            for (int r_i = r + 1; r_i < m; ++r_i)
            {
                if (walls_set.count({r_i, c}) || guards_set.count({r_i, c}))
                    break;
                valid_pos[r_i][c] = false;
            }
            for (int c_i = c + 1; c_i < n; ++c_i)
            {
                if (walls_set.count({r, c_i}) || guards_set.count({r, c_i}))
                    break;
                valid_pos[r][c_i] = false;
            }
            for (int c_i = c - 1; c_i >= 0; --c_i)
            {
                if (walls_set.count({r, c_i}) || guards_set.count({r, c_i}))
                    break;
                valid_pos[r][c_i] = false;
            }
        }

        int unoccupied_cells{0};
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
            {
                if (valid_pos[r][c])
                    ++unoccupied_cells;
            }
        return unoccupied_cells;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> guards, walls;
    
    guards = {{0,0},{1,1},{2,3}};
    walls = {{0,1},{2,2},{1,4}};
    sol.countUnguarded(4, 6, guards, walls);

    return 0;
}
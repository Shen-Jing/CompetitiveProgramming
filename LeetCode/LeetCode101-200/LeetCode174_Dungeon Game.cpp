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
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        rows = dungeon.size();
        cols = dungeon[0].size();

        return cal_minHP_bottomup(dungeon);
    }

 private:
    size_t rows, cols;
    vector<vector<int>> min_hp;

    int get_minHP(size_t row, size_t col)
    {
        if (row >= rows || col >= cols)
            return numeric_limits<int>::max();
        return min_hp[row][col];
    }

    int cal_minHP_bottomup(const vector<vector<int>>& dungeon)
    {
        min_hp.assign(rows, vector<int>(cols, 0));
        for (int r = rows - 1; r >= 0; --r)
            for (int c = cols - 1; c >= 0; --c)
            {
                int right_min = get_minHP(r, c + 1);
                int down_min  = get_minHP(r + 1, c);
                
                int next_hp = min(right_min, down_min);
                if (min_hp[r][c] == numeric_limits<int>::max())
                    min_hp[r][c] = (dungeon[r][c] >= 0) ? 1 : 1 - dungeon[r][c];
                else
                    min_hp[r][c] = max(1, next_hp - dungeon[r][c]);
            }
        return min_hp[0][0];
    }
};

int main(void)
{
    Solution sol;

    vector<vector<int>> dungeon{{-2,-3,3}, {-5,-10,1}, {10,30,-5}};
    sol.calculateMinimumHP(dungeon);

    dungeon = {{0}};
    sol.calculateMinimumHP(dungeon);

    return 0;
}
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
    int islandPerimeter(vector<vector<int>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        return simple_count(grid);
    }

 private:
    int rows, cols;
    bool out_of_bound(int row, int col)
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            return true;
        return false;
    }

    int simple_count(const vector<vector<int>> &grid)
    {
        int length = 0;
        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c])
                {
                    /* Order: Up, Down, Left, Right */
                    if (out_of_bound(r - 1, c) || !grid[r - 1][c])
                        ++length;
                    if (out_of_bound(r + 1, c) || !grid[r + 1][c])
                        ++length;
                    if (out_of_bound(r, c - 1) || !grid[r][c - 1])
                        ++length;
                    if (out_of_bound(r, c + 1) || !grid[r][c + 1])
                        ++length;
                }
            }
        return length;
    }
};

int main(void)
{

    return 0;
}
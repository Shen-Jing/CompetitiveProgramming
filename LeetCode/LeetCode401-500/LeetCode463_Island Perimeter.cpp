#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <string>
#include <vector>

static auto io = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

bool out_of_bound(int idx, int length)
{
    if (idx < 0 || idx >= length)
        return true;
    return false;
}

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int cnt = 0;
        auto rows = grid.size();
        auto cols = grid[0].size();
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c])
                {
                    if (out_of_bound(c - 1, cols) || !grid[r][c - 1])
                        ++cnt;
                    if (out_of_bound(c + 1, cols) || !grid[r][c + 1])
                        ++cnt;
                    if (out_of_bound(r - 1, rows) || !grid[r - 1][c])
                        ++cnt;
                    if (out_of_bound(r + 1, rows) || !grid[r + 1][c])
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};

int main(void)
{
    Solution sol;

    return 0;
}

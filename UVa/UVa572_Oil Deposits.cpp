#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
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

int rows, cols;

void flood_fill(vector<vector<bool>> &visited, const vector<vector<char>> &grids, int r, int c)
{
    if (r < 0 || r >= rows || c < 0 || c >= cols || grids[r][c] == '*' || visited[r][c])
        return;
    
    array<int, 3> offset{-1, 0, 1};
    // row & col offset
    visited[r][c] = true;
    for (const auto &r_off : offset)
        for (const auto &c_off : offset)
        {
            if (!r_off && !c_off)
                continue;
            flood_fill(visited, grids, r + r_off, c + c_off);
        }

}

int main(void)
{

    while (cin >> rows >> cols)
    {
        if (!rows)
            break;
        
        auto grids = vector<vector<char>>(rows, vector<char>());

        for (int r = 0; r < rows; ++r)
        {
            grids[r].reserve(cols);
            for (int c = 0; c < cols; ++c)
            {
                char mark;
                cin >> mark;
                grids[r].emplace_back(mark);
            }
        }

        auto visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        int num_deposits = 0;
        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grids[r][c] == '@' && !visited[r][c])
                {
                    flood_fill(visited, grids, r, c);
                    ++num_deposits;
                }
            }
        }

        cout << num_deposits << "\n";
    }

    return 0;
}
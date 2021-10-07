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
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        rows = image.size(), cols = image[0].size();
        old_color = image[sr][sc];
        visited.assign(rows, vector<bool>(cols, false));
        flood_fill(image, sr, sc, newColor);
        return image;
    }

 private:
    int rows, cols;
    int old_color;
    /* Up, Down, Left, Right */
    const array<array<int, 2>, 4> directions{ {{-1, 0}, {1, 0}, {0, -1}, {0, 1}} };
    vector<vector<bool>> visited;

    bool out_of_bound(const int row, const int col)
    {
        if (row < 0 || row >= rows ||
            col < 0 || col >= cols)
            return true;
        return false;
    }

    void flood_fill(vector<vector<int>> &image, int sr, int sc, const int &new_color)
    {
        image[sr][sc] = new_color;
        for (const auto &dir : directions)
        {
            int next_row = sr + dir[0], next_col = sc + dir[1];
            if (!out_of_bound(next_row, next_col) && !visited[next_row][next_col] && image[next_row][next_col] == old_color)
            {
                visited[next_row][next_col] = true;
                flood_fill(image, next_row, next_col, new_color);
            }
        }
    }
};

int main(void)
{
    Solution sol;

    vector<vector<int>> image{{0,0,0},{0,1,0}};
    sol.floodFill(image, 1, 1, 2);

    image.assign({{0,0,0},{0,1,1}});
    sol.floodFill(image, 1, 1, 1);

    return 0;
}
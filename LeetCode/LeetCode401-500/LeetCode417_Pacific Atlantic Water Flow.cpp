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
#include <regex>
#include <set>
#include <span>
#include <stack>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
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
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        rows_ = heights.size();
        cols_ = heights[0].size();
        memo_.assign(rows_, vector<int>(cols_, -1));
        by_DFS(heights, 0, 0);
        return ans_;
    }

 private:
    int rows_, cols_;
    vector<vector<int>> memo_;
    vector<vector<int>> ans_;
    bool by_DFS(const vector<vector<int>> &heights, int cur_r, int cur_c)
    {
        if (memo_[cur_r][cur_c] == 2)
            return true;
        if (memo_[cur_r][cur_c] != -1)
            return false;
        memo_[cur_r][cur_c] = 0;
        // North, South, East, West
        array<array<int, 2>, 4> dirs{{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}};
        for (const auto &dir : dirs)
        {
            int new_r = cur_r + dir[0],
                new_c = cur_c + dir[1];
            if (new_r < 0 || new_c) 
            {
                if (memo_[cur_r][cur_c] == 1)
                    continue;
                memo_[cur_r][cur_c] = 1;
            }
            else if (new_r == rows_ || new_c == cols_)
            {
                if (memo_[cur_r][cur_c] == 2)
                    continue;
                memo_[cur_r][cur_c] = 1;
            }
            else if (memo_[cur_r][cur_c] == 2 || by_DFS(heights, new_r, new_c))
            {
                ans_.emplace_back(cur_r, cur_c);
                return true;
            }
        }
        return false;
    }
};

int main(void)
{

    return 0;
}
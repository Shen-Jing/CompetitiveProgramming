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

struct Edge
{
    int u, v;
    int diff;
    Edge(int u = 0, int v = 0, int d = 0) : u(u), v(v), diff(d) {}
};
class UnionFind
{
 public:
    vector<int> parents;
    vector<int> ranks;
    vector<Edge> edges;
    UnionFind(const vector<vector<int>> &heights)
    {
        int rows = heights.size(), cols = heights[0].size();
        parents.assign(rows * cols, 0);
        ranks.assign(rows * cols, 0);

        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c)
            {
                if (r > 0)
                {
                    edges.emplace_back(r * cols + c, (r - 1) * cols + c, abs(heights[r][c] - heights[r - 1][c]));
                }
                if (c > 0)
                {
                    edges.emplace_back(r * cols + c, r * cols + (c - 1), abs(heights[r][c] - heights[r][c - 1]));
                }
                parents[(r * cols + c)] = r * cols + c;
            }
    }

    int find_root(int x)
    {
        return (parents[x] == x) ? x : parents[x] = find_root(parents[x]);
    }

    void union_by_rank(int x, int y)
    {
        int root_x = find_root(x),
            root_y = find_root(y);
        if (root_x != root_y)
        {
            if (ranks[root_x] > ranks[root_y])
                parents[root_y] = root_x;
            else if (ranks[root_y] > ranks[root_x])
                parents[root_x] = root_y;
            else
            {
                parents[root_y] = root_x;
                ++ranks[root_x];
            }
        }
    }
};

class Solution
{
 public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        rows_ = heights.size();
        cols_ = heights[0].size();
        return union_and_find(heights);
        // visited_.assign(rows_, vector<bool>(cols_, false));
        // min_efforts_.assign(rows_, vector<int>(cols_, numeric_limits<int>::max()));
        // int effort{0};
        // brute_force_backtrack(heights, 0, 0, effort);
        return ans_;
    }

 private:
    int rows_, cols_, 
        ans_ = numeric_limits<int>::max();
    array<array<int, 2>, 4> dirs_{{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
    vector<vector<int>> min_efforts_;
    vector<vector<bool>> visited_;
    bool is_out_of_bound(const int &r, const int &c)
    {
        if (r < 0 || c < 0 ||
            r >= rows_ || c >= cols_)
            return true;
        return false;
    }

    void brute_force_backtrack(const vector<vector<int>> &heights, int cur_r, int cur_c, int &cur_effort)
    {
        if (cur_r == rows_ - 1 && cur_c == cols_ - 1)
        {
            ans_ = min(ans_, cur_effort);
            return;
        }
        visited_[cur_r][cur_c] = true;
        for (const auto &dir : dirs_)
        {
            int nxt_r = cur_r + dir[0],
                nxt_c = cur_c + dir[1];
            if (is_out_of_bound(nxt_r, nxt_c) || visited_[nxt_r][nxt_c])
                continue;
            int old_effort = cur_effort;
            cur_effort = max(cur_effort, abs(heights[nxt_r][nxt_c] - heights[cur_r][cur_c]));
            brute_force_backtrack(heights, nxt_r, nxt_c, cur_effort);
            cur_effort = old_effort;
        }
        visited_[cur_r][cur_c] = false;
    }

    int union_and_find(const vector<vector<int>> &heights)
    {
        if (rows_ == 1 && cols_ == 1)
            return 0;
        UnionFind union_find(heights);
        sort(union_find.edges.begin(), union_find.edges.end(), [](const auto &lhs, const auto &rhs)
            {
                return lhs.diff < rhs.diff;
            });
        
        for (const auto &e : union_find.edges)
        {
            int src = e.u, 
                dst = e.v;
            union_find.union_by_rank(src, dst);
            if (union_find.find_root(0) == union_find.find_root(rows_ * cols_ - 1))
                return e.diff;
        }
        return -1;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> heights;

    heights = {{3}};
    cout << sol.minimumEffortPath(heights) << "\n";

    heights = {{4,3,4,10,5,5,9,2},{10,8,2,10,9,7,5,6},{5,8,10,10,10,7,4,2},{5,1,3,1,1,3,1,9},{6,4,10,6,10,9,4,6}};
    cout << sol.minimumEffortPath(heights) << "\n";

    return 0;
}

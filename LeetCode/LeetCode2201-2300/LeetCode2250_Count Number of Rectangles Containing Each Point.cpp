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
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points)
    {
    }

 private:
    const int k_max_pos = 50000;
    vector<vector<int>> pos_rect_cnt_;

    vector<int> my_brute_force(vector<vector<int>>& rectangles, vector<vector<int>>& points)
    {
        pos_rect_cnt_.assign(k_max_pos, vector<int>(k_max_pos, 0));
        for (const auto &rect : rectangles)
            enumerate_points(rect);

        vector<int> ans;
        for (const auto &p : points)
        {
            ans.emplace_back(pos_rect_cnt_[p[0]][p[1]]);
        }
        return ans;
    }

    void enumerate_points(const vector<int> &rect)
    {
        int x = rect[0], y = rect[1];
        for (int xi = 1; xi <= x; ++xi)
            for (int yi = 1; yi <= y; ++yi)
                ++pos_rect_cnt_[xi][yi];
    }
};

int main(void)
{

    return 0;
}
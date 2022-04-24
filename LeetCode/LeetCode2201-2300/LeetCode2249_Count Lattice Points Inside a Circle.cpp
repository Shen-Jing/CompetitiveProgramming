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
    int countLatticePoints(vector<vector<int>>& circles)
    {
        for (const auto &circle : circles)
            enumerate_points(circle);
        return points_set_.size();
        return points_str_set_.size();
    }

 private:
    set<pair<int, int>> points_set_;
    unordered_set<string> points_str_set_;

    void enumerate_points(const vector<int> &c)
    {
        int x = c[0], y = c[1], r = c[2];
        for (int xi = x - r; xi <= x + r; ++xi)
            for (int yi = y - r; yi <= y + r; ++yi)
                if (pow(x - xi, 2) + pow(y - yi, 2) <= pow(r, 2))
                    points_set_.insert({xi, yi});
                    // points_set_.emplace(xi, yi);
                    // points_set_.emplace(make_pair(xi, yi));
                    // points_str_set_.insert(to_string(xi) + " " + to_string(yi));
                    // points_str_set_.emplace(to_string(xi) + " " + to_string(yi));
    }

    void put_point(const int &x,  const int &y, 
                   const int &xi, const int &yi, const int &r)
    {
        if (pow(x - xi, 2) + pow(y - yi, 2) <= pow(r, 2))
        {
            points_str_set_.emplace(to_string(xi) + " " + to_string(yi));
            points_str_set_.emplace(to_string(xi + 2 * (x - xi)) + " " + to_string(yi));
        }
    }

    /* BUT WA */
    void enhanced_enumerate_points(const vector<int> &c)
    {
        int x = c[0], y = c[1], r = c[2];
        for (int xi = x - r; xi <= x; ++xi)
        {
            int yi = y;
            put_point(x, y, xi, yi, r);
            for (int i = x - xi; i < r; ++i)
            {
                ++yi;
                put_point(x, y, xi, yi, r);
            }
            yi = y;
            for (int i = x - xi; i < r; ++i)
            {
                --yi;
                put_point(x, y, xi, yi, r);
            }
        }
    }
};

int main(void)
{
    Solution sol;

    vector<vector<int>> circles;
    
    circles = {{8, 9, 6}};
    sol.countLatticePoints(circles);

    circles = {{2, 2, 1}};
    sol.countLatticePoints(circles);

    return 0;
}
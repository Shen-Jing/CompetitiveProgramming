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
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        return STL_sort(points, k);
    }

 private:
    inline float get_squared_distance(int x1, int y1, int x2 = 0, int y2 = 0)
    {
        return pow(x1 - x2, 2) + pow(y1 - y2, 2);
    }

    vector<vector<int>> STL_sort(const vector<vector<int>> &points, int k)
    {
        sort(points.begin(), points.end(), [&](const auto &lhs, const auto &rhs){
            return get_squared_distance(lhs[0], lhs[1]) < get_squared_distance(rhs[0], rhs[1]);
        });
        
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};

int main(void)
{

    return 0;
}
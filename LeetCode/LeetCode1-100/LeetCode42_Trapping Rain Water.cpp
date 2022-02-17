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
    int trap(vector<int> &height)
    {
        return brute_force(height);
    }

 private:
    int brute_force(vector<int> &heights)
    {
        int trap_water{0};
        int sz = heights.size();
        for (int idx = 1; idx <= sz - 2; ++idx)
        {
            int left_max, right_max;
            left_max = right_max = heights[idx];
            int left = idx, 
                right = idx;
            while (--left >= 0)
                left_max = max(left_max, heights[left]);
            while (++right < sz)
                right_max = max(right_max, heights[right]);

            trap_water += min(left_max, right_max) - heights[idx];
        }
        return trap_water;
    }
};

int main(void)
{
    Solution sol;

    vector<int> height = {4,2,0,3,2,5};
    sol.trap(height);

    return 0;
}
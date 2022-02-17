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
        return DP(height);
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

    int DP(vector<int> &heights)
    {
        int sz = heights.size();
        vector<int> all_left_max(sz, 0), all_right_max(sz, 0);
        all_left_max[0] = heights[0];
        all_right_max[sz - 1] = heights[sz - 1];
        for (int i = 1; i < sz; ++i)
        {
            all_left_max[i] = max(all_left_max[i - 1], heights[i]);
            all_right_max[(sz - 1) - i] = max(all_right_max[(sz - 1) - i + 1], heights[(sz - 1) - i]);
        }

        int trap_water{0};
        for (int i = 1; i < sz - 1; ++i)
            trap_water += min(all_left_max[i], all_right_max[i]) - heights[i];
        return trap_water;
    }
};

int main(void)
{
    Solution sol;

    vector<int> height;

    height = {0,1,0,2,1,0,1,3,2,1,2,1};
    sol.trap(height);

    height = {4,2,0,3,2,5};
    sol.trap(height);

    return 0;
}
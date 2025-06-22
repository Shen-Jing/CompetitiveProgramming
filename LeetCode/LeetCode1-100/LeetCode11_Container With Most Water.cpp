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
    int maxArea(vector<int> &height)
    {
        return two_pointer(height);
    }

 private:
    int brute_force(vector<int> &heights)
    {
        int max_area{0};
        int sz = heights.size();
        for (int i = 0; i < sz; ++i)
            for (int j = i + 1; j < sz; ++j)
            {
                int curr_area = (j - i) * min(heights[i], heights[j]);
                max_area = max(max_area, curr_area);
            }
        return max_area;
    }

    int two_pointer(vector<int> &heights)
    {
        int left = 0, right = heights.size() - 1;
        int max_area{0};
        while (left < right)
        {
            int curr_area = min(heights[left], heights[right]) * (right - left);
            max_area = max(max_area, curr_area);

            if (heights[left] < heights[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return max_area;
    }
};

int main(void)
{

    return 0;
}
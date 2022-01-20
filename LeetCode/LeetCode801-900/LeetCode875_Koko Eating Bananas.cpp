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
    int minEatingSpeed(vector<int> &piles, int h)
    {
        return binary_search_min_speed(piles, h);
    }

 private:
    int get_need_hours(const vector<int> &piles, int speed)
    {
        int need_hours{0};
        for (const auto &bananas : piles)
        {
            need_hours += bananas / speed;
            need_hours += (bananas % speed == 0) ? 0 : 1; 
        }
        return need_hours;
    }

    int binary_search_min_speed(vector<int> &piles, const int &h)
    {
        int left{1}, right{*max_element(piles.begin(), piles.end())};
        while (left < right)
        {
            int mid = left + ((right - left) >> 1);
            if (get_need_hours(piles, mid) <= h)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main(void)
{
    Solution sol;

    vector<int> piles{3,6,7,11};  // Example
    sol.minEatingSpeed(piles, 8);

    piles = {3,6,7,11};  // My example
    sol.minEatingSpeed(piles, 100);

    piles = {1000000000};  // 116 / 119 test cases passed.
    sol.minEatingSpeed(piles, 2);  // the precision problem

    return 0;
}
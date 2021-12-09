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
    bool canReach(vector<int> &arr, int start)
    {
        const auto sz = arr.size();
        seen.assign(sz, false);
        return my_can_reach(arr, start, 0);
    }

 private:
    vector<bool> seen;
    bool my_can_reach(const vector<int> &arr, int start, int target_value)
    {
        if (start < 0 || start >= arr.size() ||
            seen[start])
            return false;
        if (arr[start] == target_value)
            return true;

        seen[start] = true;
        return my_can_reach(arr, start + arr[start], target_value) ||
               my_can_reach(arr, start - arr[start], target_value);
    }
};

int main(void)
{
    Solution sol;

    vector<int> arr{0,3,0,6,3,3,4};
    sol.canReach(arr, 6);  // True

    return 0;
}
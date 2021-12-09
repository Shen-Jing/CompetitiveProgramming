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
        int target_pos = find(arr.begin(), arr.end(), 0) - arr.begin();
        return can_reach(arr, start, target_pos);
    }

 private:
    vector<bool> seen;
    bool can_reach(const vector<int> &arr, int start, int target)
    {
        if (start < 0 || start >= arr.size() ||
            seen[start])
            return false;
        if (start == target)
            return true;

        seen[start] = true;
        return can_reach(arr, start + arr[start], target) ||
               can_reach(arr, start - arr[start], target);
    }
};

int main(void)
{

    return 0;
}
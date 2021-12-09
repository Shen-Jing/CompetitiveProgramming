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
        set<int> targets;
        for (int i = 0; i < sz; ++i)
            if (!arr[i])
                targets.emplace(i);
        return can_reach(arr, start, targets);
    }

 private:
    vector<bool> seen;
    bool can_reach(const vector<int> &arr, int start, const set<int> &targets)
    {
        if (start < 0 || start >= arr.size() ||
            seen[start])
            return false;
        if (targets.count(start))
            return true;

        seen[start] = true;
        return can_reach(arr, start + arr[start], targets) ||
               can_reach(arr, start - arr[start], targets);
    }
};

int main(void)
{

    return 0;
}
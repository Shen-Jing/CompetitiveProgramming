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
    int minimumOperations(vector<int>& nums, int start, int goal)
    {
        for (int i = 0; i < nums.size(); ++i)
            backtrack(nums, i, 0, start, goal);
    }

    bool backtrack(const vector<int> &nums, int idx, int operations, int start, int goal)
    {
        if (idx == nums.size() || start < 0 || start > 1000)
        {
            if (start == goal)
            {
                return true;
            }
            return false;
        }
        
            backtrack(nums, idx + 1, start, goal);
    }

 private:
    map<int, int> min_operations;
};

int main(void)
{

    return 0;
}
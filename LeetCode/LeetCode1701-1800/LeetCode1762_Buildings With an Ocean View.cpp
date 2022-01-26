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
    vector<int> findBuildings(vector<int> &heights)
    {
    }

 private:
    vector<int> monotonic_stack(vector<int> &heights)
    {
        stack<size_t> stk;
        auto sz = heights.size();
        for (size_t i = 0; i < sz; ++i)
        {
            while (!stk.empty() && heights[i] >= heights[stk.top()])
                stk.pop();
            stk.emplace(i);
        }
        
        vector<int> ans;
        while (!stk.empty())
        {
            ans.emplace_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(void)
{

    return 0;
}